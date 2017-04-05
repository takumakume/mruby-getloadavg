/*
** mrb_getloadavg.c - Getloadavg class
**
** Copyright (c) Takuma Kume 2017
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_getloadavg.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_getloadavg_data;

static const struct mrb_data_type mrb_getloadavg_data_type = {
  "mrb_getloadavg_data", mrb_free,
};

static mrb_value mrb_getloadavg_init(mrb_state *mrb, mrb_value self)
{
  mrb_getloadavg_data *data;
  char *str;
  int len;

  data = (mrb_getloadavg_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_getloadavg_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_getloadavg_data *)mrb_malloc(mrb, sizeof(mrb_getloadavg_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_getloadavg_hello(mrb_state *mrb, mrb_value self)
{
  mrb_getloadavg_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_getloadavg_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_getloadavg_gem_init(mrb_state *mrb)
{
  struct RClass *getloadavg;
  getloadavg = mrb_define_class(mrb, "Getloadavg", mrb->object_class);
  mrb_define_method(mrb, getloadavg, "initialize", mrb_getloadavg_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, getloadavg, "hello", mrb_getloadavg_hello, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, getloadavg, "hi", mrb_getloadavg_hi, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_getloadavg_gem_final(mrb_state *mrb)
{
}

