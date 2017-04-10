/*
** mrb_getloadavg.c - Getloadavg class
**
** Copyright (c) Takuma Kume 2017
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/numeric.h"
#include "mruby/array.h"
#include "mrb_getloadavg.h"
#include "stdlib.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

static mrb_value mrb_getloadavg(mrb_state *mrb, mrb_value self)
{
  mrb_int nelem;
  mrb_value mrb_loadavg = mrb_ary_new(mrb);

  int inelem;
  double loadavg[3];

  mrb_get_args(mrb, "i", &nelem);

  inelem = (int)nelem;

  if (getloadavg(loadavg, inelem) < 0)
    mrb_raise(mrb, E_RUNTIME_ERROR, "getloadavg syscall failed");

  mrb_ary_push(mrb, mrb_loadavg, mrb_float_value(mrb, loadavg[0]));
  mrb_ary_push(mrb, mrb_loadavg, mrb_float_value(mrb, loadavg[1]));
  mrb_ary_push(mrb, mrb_loadavg, mrb_float_value(mrb, loadavg[2]));

  return mrb_loadavg;
}

void mrb_mruby_getloadavg_gem_init(mrb_state *mrb)
{
  struct RClass *getloadavg;
  getloadavg = mrb_define_class(mrb, "Getloadavg", mrb->object_class);
  mrb_define_class_method(mrb, getloadavg, "getloadavg", mrb_getloadavg, MRB_ARGS_REQ(1));
  DONE;
}

void mrb_mruby_getloadavg_gem_final(mrb_state *mrb)
{
}
