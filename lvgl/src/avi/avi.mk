CSRCS += avilib.c


DEPPATH += --dep-path $(LVGL_DIR)/$(LVGL_DIR_NAME)/src/avi
VPATH += :$(LVGL_DIR)/$(LVGL_DIR_NAME)/src/avi

CFLAGS += "-I$(LVGL_DIR)/$(LVGL_DIR_NAME)/src/avi"
