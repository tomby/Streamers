#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <chunk.h>

#include "input.h"
#include "dbg.h"

struct input_desc *input_open(const char *fname)
{
  return NULL;
}

void input_close(struct input_desc *s)
{
}

int input_get(struct input_desc *dummy, struct chunk *c)
{
  char buff[64];
  static int id;

  sprintf(buff, "Chunk %d", id);
  c->id = id;
  c->timestamp = 40 * id++;
  c->data = strdup(buff);
  c->size = strlen(c->data) + 1;
  c->attributes_size = 0;
  c->attributes = NULL;

  dprintf("Generate Chunk[%d] (TS: %llu): %s\n", c->id, c->timestamp, c->data);

  return 1;
}