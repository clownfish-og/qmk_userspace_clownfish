SRC += clownfish.c

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += rgb_keys.c
endif
