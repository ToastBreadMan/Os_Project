#pragma once

#include "len.c"
#include "itoa.c"

int textmode_x = 0;
int textmode_y = 0;

void putchar(char text) {
    short * vidmem = (short *)0xb8000;
    int color = 0x0F00;

    if (text == '\n') {
        textmode_y++;
        return;
    } else if (text == '\r') {
        textmode_x = 0;
        return;
    } else if (text == '\b') {
        textmode_x--;
        vidmem[(textmode_x+1)+textmode_y*80] = color | ' ';
        return;
    }

    vidmem[textmode_x+textmode_y*80] = color | text;
    textmode_x++;

    if (textmode_x > 80) {
        textmode_x = 0;
        textmode_y++;
    }
}

void putchar_color(char text, int color) {
    short * vidmem = (short *)0xb8000;

    if (text == '\n') {
        textmode_y++;
        return;
    } else if (text == '\r') {
        textmode_x = 0;
        return;
    } else if (text == '\b') {
        textmode_x--;
        vidmem[(textmode_x+1)+textmode_y*80] = color | ' ';
        return;
    }

    vidmem[textmode_x+textmode_y*80] = color | text;
    textmode_x++;

    if (textmode_x > 80) {
        textmode_x = 0;
        textmode_y++;
    }
}

void printf(char *text, ...)
{
  char **arg = (char **)&text;
  int c;
  char buffer[20];

  arg++;

  while ((c = *text++) != 0)
    {
      if (c != '%')
      {
        if (c == '\n')
        {
            textmode_x = 0;
            textmode_y++;
        }
        else if (c == '\t')
        {
            textmode_x += 4;

            if (textmode_x > 80) {
                textmode_x = 0;
                textmode_y++;
            }
        }
        else
        {
            putchar(c);
        }
      }
      else
        {
          char *p, *p2;
          int pad0 = 0, pad = 0;

          c = *text++;
          if (c == '0')
            {
              pad0 = 1;
              c = *text++;
            }

          if (c >= '0' && c <= '9')
            {
              pad = c - '0';
              c = *text++;
            }

          switch (c)
            {
            case 'c':
                putchar(c);
                break;
            case 'd':
            case 'u':
            case 'x':
              itoa (buffer, c, *((int *) arg++));
              p = buffer;
              goto string;
              break;

            case 's':
              p = *arg++;
              if (! p)
                p = "NULL";

            string:
              for (p2 = p; *p2; p2++);
              for (; p2 < p + pad; p2++)
              {
                putchar(pad0 ? '0' : ' ');
              }
              while (*p)
              {
                putchar(*p++);
              }
              break;

            default:
              putchar(*((int *) arg++));
              break;
            }
        }
    }
}
