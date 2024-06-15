// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2024 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/of.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct mdss_dsi_nt36672 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
};

static inline
struct mdss_dsi_nt36672 *to_mdss_dsi_nt36672(struct drm_panel *panel)
{
	return container_of(panel, struct mdss_dsi_nt36672, panel);
}

static void mdss_dsi_nt36672_reset(struct mdss_dsi_nt36672 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
}

static int mdss_dsi_nt36672_on(struct mdss_dsi_nt36672 *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_write_seq(dsi, 0xff, 0x20);
	mipi_dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x01, 0x33);
	mipi_dsi_dcs_write_seq(dsi, 0x06, 0x96);
	mipi_dsi_dcs_write_seq(dsi, 0x07, 0x9c);
	mipi_dsi_dcs_write_seq(dsi, 0x0e, 0x2d);
	mipi_dsi_dcs_write_seq(dsi, 0x0f, 0x2c);
	mipi_dsi_dcs_write_seq(dsi, 0x1d, 0x33);
	mipi_dsi_dcs_write_seq(dsi, 0x68, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0x6d, 0x66);
	mipi_dsi_dcs_write_seq(dsi, 0x69, 0x99);
	mipi_dsi_dcs_write_seq(dsi, 0x89, 0x0f);
	mipi_dsi_dcs_write_seq(dsi, 0x95, 0xd7);
	mipi_dsi_dcs_write_seq(dsi, 0x96, 0xd7);
	mipi_dsi_dcs_write_seq(dsi, 0xff, 0x24);
	mipi_dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x00, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x01, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x02, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x03, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x04, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x05, 0x11);
	mipi_dsi_dcs_write_seq(dsi, 0x06, 0x0c);
	mipi_dsi_dcs_write_seq(dsi, 0x07, 0x1b);
	mipi_dsi_dcs_write_seq(dsi, 0x08, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0x09, 0x04);
	mipi_dsi_dcs_write_seq(dsi, 0x0a, 0x19);
	mipi_dsi_dcs_write_seq(dsi, 0x0b, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x0c, 0x14);
	mipi_dsi_dcs_write_seq(dsi, 0x0d, 0x16);
	mipi_dsi_dcs_write_seq(dsi, 0x0e, 0x18);
	mipi_dsi_dcs_write_seq(dsi, 0x0f, 0x17);
	mipi_dsi_dcs_write_seq(dsi, 0x10, 0x15);
	mipi_dsi_dcs_write_seq(dsi, 0x11, 0x13);
	mipi_dsi_dcs_write_seq(dsi, 0x12, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x13, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x14, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x15, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x16, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x17, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x18, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x19, 0x1b);
	mipi_dsi_dcs_write_seq(dsi, 0x1a, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0x1b, 0x04);
	mipi_dsi_dcs_write_seq(dsi, 0x1c, 0x19);
	mipi_dsi_dcs_write_seq(dsi, 0x1d, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x1e, 0x14);
	mipi_dsi_dcs_write_seq(dsi, 0x1f, 0x16);
	mipi_dsi_dcs_write_seq(dsi, 0x20, 0x18);
	mipi_dsi_dcs_write_seq(dsi, 0x21, 0x17);
	mipi_dsi_dcs_write_seq(dsi, 0x22, 0x15);
	mipi_dsi_dcs_write_seq(dsi, 0x23, 0x13);
	mipi_dsi_dcs_write_seq(dsi, 0x2f, 0x02);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_PARTIAL_ROWS, 0x03);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_PARTIAL_COLUMNS, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0x32, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0x33, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0x34, 0x02);

	ret = mipi_dsi_dcs_set_tear_on(dsi, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	if (ret < 0) {
		dev_err(dev, "Failed to set tear on: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_ADDRESS_MODE, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x37, 0x20);
	mipi_dsi_dcs_write_seq(dsi, 0x38, 0x67);
	mipi_dsi_dcs_write_seq(dsi, 0x39, 0x67);
	mipi_dsi_dcs_write_seq(dsi, 0x3f, 0x67);
	mipi_dsi_dcs_write_seq(dsi, 0x60, 0x10);
	mipi_dsi_dcs_write_seq(dsi, 0x68, 0xc2);
	mipi_dsi_dcs_write_seq(dsi, 0x6f, 0x10);
	mipi_dsi_dcs_write_seq(dsi, 0x78, 0x80);
	mipi_dsi_dcs_write_seq(dsi, 0x79, 0x22);
	mipi_dsi_dcs_write_seq(dsi, 0x7a, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x7b, 0x9c);
	mipi_dsi_dcs_write_seq(dsi, 0x7c, 0x80);
	mipi_dsi_dcs_write_seq(dsi, 0x7d, 0x05);
	mipi_dsi_dcs_write_seq(dsi, 0x7e, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x80, 0x44);
	mipi_dsi_dcs_write_seq(dsi, 0x81, 0x05);
	mipi_dsi_dcs_write_seq(dsi, 0x92, 0x74);
	mipi_dsi_dcs_write_seq(dsi, 0x93, 0x0c);
	mipi_dsi_dcs_write_seq(dsi, 0x94, 0x2e);
	mipi_dsi_dcs_write_seq(dsi, 0x99, 0x33);
	mipi_dsi_dcs_write_seq(dsi, 0x9b, 0xff);
	mipi_dsi_dcs_write_seq(dsi, 0xa3, 0x91);
	mipi_dsi_dcs_write_seq(dsi, 0xb3, 0x2a);
	mipi_dsi_dcs_write_seq(dsi, 0xb4, 0x94);
	mipi_dsi_dcs_write_seq(dsi, 0xb5, 0x04);
	mipi_dsi_dcs_write_seq(dsi, 0xd6, 0x04);
	mipi_dsi_dcs_write_seq(dsi, 0xd7, 0x5d);
	mipi_dsi_dcs_write_seq(dsi, 0xd8, 0x13);
	mipi_dsi_dcs_write_seq(dsi, 0xd9, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xdc, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xdd, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xde, 0x11);
	mipi_dsi_dcs_write_seq(dsi, 0xdf, 0x3a);
	mipi_dsi_dcs_write_seq(dsi, 0xe0, 0x39);
	mipi_dsi_dcs_write_seq(dsi, 0xe9, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xed, 0x40);
	mipi_dsi_dcs_write_seq(dsi, 0xee, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xef, 0x54);
	mipi_dsi_dcs_write_seq(dsi, 0xf0, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x73, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x75, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x82, 0x13);
	mipi_dsi_dcs_write_seq(dsi, 0x83, 0x22);
	mipi_dsi_dcs_write_seq(dsi, 0x84, 0x31);
	mipi_dsi_dcs_write_seq(dsi, 0x85, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x86, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x87, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x88, 0x13);
	mipi_dsi_dcs_write_seq(dsi, 0x89, 0x22);
	mipi_dsi_dcs_write_seq(dsi, 0x8a, 0x31);
	mipi_dsi_dcs_write_seq(dsi, 0x8b, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x8c, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x8d, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x8e, 0xf4);
	mipi_dsi_dcs_write_seq(dsi, 0x8f, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0xff, 0x25);
	mipi_dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x0a, 0x81);
	mipi_dsi_dcs_write_seq(dsi, 0x0b, 0xce);
	mipi_dsi_dcs_write_seq(dsi, 0x0c, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x17, 0x82);
	mipi_dsi_dcs_write_seq(dsi, 0x19, 0x0e);
	mipi_dsi_dcs_write_seq(dsi, 0x21, 0x1c);
	mipi_dsi_dcs_write_seq(dsi, 0x22, 0x1c);
	mipi_dsi_dcs_write_seq(dsi, 0x24, 0x74);
	mipi_dsi_dcs_write_seq(dsi, 0x25, 0x74);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_PARTIAL_ROWS, 0x1d);
	mipi_dsi_dcs_write_seq(dsi, 0x3f, 0x13);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_VSYNC_TIMING, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0x62, 0x3f);
	mipi_dsi_dcs_write_seq(dsi, 0x63, 0x83);
	mipi_dsi_dcs_write_seq(dsi, 0x65, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x66, 0x5d);
	mipi_dsi_dcs_write_seq(dsi, 0x67, 0x12);
	mipi_dsi_dcs_write_seq(dsi, 0x68, 0x50);
	mipi_dsi_dcs_write_seq(dsi, 0x69, 0x10);
	mipi_dsi_dcs_write_seq(dsi, 0x6d, 0x0d);
	mipi_dsi_dcs_write_seq(dsi, 0x6e, 0x48);
	mipi_dsi_dcs_write_seq(dsi, 0x71, 0x5d);
	mipi_dsi_dcs_write_seq(dsi, 0x72, 0x65);
	mipi_dsi_dcs_write_seq(dsi, 0x73, 0x3b);
	mipi_dsi_dcs_write_seq(dsi, 0x74, 0x90);
	mipi_dsi_dcs_write_seq(dsi, 0x77, 0x63);
	mipi_dsi_dcs_write_seq(dsi, 0x78, 0x25);
	mipi_dsi_dcs_write_seq(dsi, 0x7e, 0x1d);
	mipi_dsi_dcs_write_seq(dsi, 0x7f, 0x08);
	mipi_dsi_dcs_write_seq(dsi, 0x82, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x86, 0x4d);
	mipi_dsi_dcs_write_seq(dsi, 0x8f, 0x04);
	mipi_dsi_dcs_write_seq(dsi, 0xc3, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0xd0, 0x80);
	mipi_dsi_dcs_write_seq(dsi, 0xd7, 0x80);
	mipi_dsi_dcs_write_seq(dsi, 0xd8, 0x80);
	mipi_dsi_dcs_write_seq(dsi, 0xff, 0x26);
	mipi_dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x06, 0xc8);
	mipi_dsi_dcs_write_seq(dsi, 0x0c, 0x0b);
	mipi_dsi_dcs_write_seq(dsi, 0x0f, 0x06);
	mipi_dsi_dcs_write_seq(dsi, 0x10, 0x07);
	mipi_dsi_dcs_write_seq(dsi, 0x12, 0xb4);
	mipi_dsi_dcs_write_seq(dsi, 0x19, 0x17);
	mipi_dsi_dcs_write_seq(dsi, 0x1a, 0x20);
	mipi_dsi_dcs_write_seq(dsi, 0x1d, 0x16);
	mipi_dsi_dcs_write_seq(dsi, 0x1e, 0xa7);
	mipi_dsi_dcs_write_seq(dsi, 0x81, 0x1c);
	mipi_dsi_dcs_write_seq(dsi, 0x85, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x88, 0x10);
	mipi_dsi_dcs_write_seq(dsi, 0x8a, 0x1a);
	mipi_dsi_dcs_write_seq(dsi, 0x8c, 0x44);
	mipi_dsi_dcs_write_seq(dsi, 0x8d, 0x33);
	mipi_dsi_dcs_write_seq(dsi, 0x8e, 0x22);
	mipi_dsi_dcs_write_seq(dsi, 0x8f, 0x22);
	mipi_dsi_dcs_write_seq(dsi, 0x90, 0x33);
	mipi_dsi_dcs_write_seq(dsi, 0x91, 0x44);
	mipi_dsi_dcs_write_seq(dsi, 0x99, 0x20);
	mipi_dsi_dcs_write_seq(dsi, 0xff, 0x27);
	mipi_dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x13, 0x08);
	mipi_dsi_dcs_write_seq(dsi, 0x14, 0x43);
	mipi_dsi_dcs_write_seq(dsi, 0x16, 0xb8);
	mipi_dsi_dcs_write_seq(dsi, 0x17, 0xb8);
	mipi_dsi_dcs_write_seq(dsi, 0x7a, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xff, 0x10);

	ret = mipi_dsi_dcs_exit_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to exit sleep mode: %d\n", ret);
		return ret;
	}
	msleep(120);

	ret = mipi_dsi_dcs_set_display_on(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display on: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_CONTROL_DISPLAY, 0x2c);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_CABC_MIN_BRIGHTNESS, 0x0a);

	return 0;
}

static int mdss_dsi_nt36672_off(struct mdss_dsi_nt36672 *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_off(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display off: %d\n", ret);
		return ret;
	}
	usleep_range(10000, 11000);

	ret = mipi_dsi_dcs_enter_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to enter sleep mode: %d\n", ret);
		return ret;
	}
	msleep(150);

	return 0;
}

static int mdss_dsi_nt36672_prepare(struct drm_panel *panel)
{
	struct mdss_dsi_nt36672 *ctx = to_mdss_dsi_nt36672(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	mdss_dsi_nt36672_reset(ctx);

	ret = mdss_dsi_nt36672_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	return 0;
}

static int mdss_dsi_nt36672_unprepare(struct drm_panel *panel)
{
	struct mdss_dsi_nt36672 *ctx = to_mdss_dsi_nt36672(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = mdss_dsi_nt36672_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	return 0;
}

static const struct drm_display_mode mdss_dsi_nt36672_mode = {
	.clock = (1080 + 30 + 10 + 30) * (2160 + 10 + 2 + 5) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 30,
	.hsync_end = 1080 + 30 + 10,
	.htotal = 1080 + 30 + 10 + 30,
	.vdisplay = 2160,
	.vsync_start = 2160 + 10,
	.vsync_end = 2160 + 10 + 2,
	.vtotal = 2160 + 10 + 2 + 5,
	.width_mm = 68,
	.height_mm = 136,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int mdss_dsi_nt36672_get_modes(struct drm_panel *panel,
				      struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &mdss_dsi_nt36672_mode);
}

static const struct drm_panel_funcs mdss_dsi_nt36672_panel_funcs = {
	.prepare = mdss_dsi_nt36672_prepare,
	.unprepare = mdss_dsi_nt36672_unprepare,
	.get_modes = mdss_dsi_nt36672_get_modes,
};

static int mdss_dsi_nt36672_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int mdss_dsi_nt36672_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness & 0xff;
}

static const struct backlight_ops mdss_dsi_nt36672_bl_ops = {
	.update_status = mdss_dsi_nt36672_bl_update_status,
	.get_brightness = mdss_dsi_nt36672_bl_get_brightness,
};

static struct backlight_device *
mdss_dsi_nt36672_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 255,
		.max_brightness = 255,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &mdss_dsi_nt36672_bl_ops, &props);
}

static int mdss_dsi_nt36672_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct mdss_dsi_nt36672 *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_MODE_VIDEO_HSE |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

	drm_panel_init(&ctx->panel, dev, &mdss_dsi_nt36672_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);
	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = mdss_dsi_nt36672_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void mdss_dsi_nt36672_remove(struct mipi_dsi_device *dsi)
{
	struct mdss_dsi_nt36672 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id mdss_dsi_nt36672_of_match[] = {
	{ .compatible = "mdss,dsi-nt36672" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, mdss_dsi_nt36672_of_match);

static struct mipi_dsi_driver mdss_dsi_nt36672_driver = {
	.probe = mdss_dsi_nt36672_probe,
	.remove = mdss_dsi_nt36672_remove,
	.driver = {
		.name = "panel-mdss-dsi-nt36672",
		.of_match_table = mdss_dsi_nt36672_of_match,
	},
};
module_mipi_dsi_driver(mdss_dsi_nt36672_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for B2N nt36672 FHD video mode dsi panel");
MODULE_LICENSE("GPL");
