/*************************************************************************

    Circus Charlie

*************************************************************************/

class circusc_state : public driver_device
{
public:
	circusc_state(running_machine &machine, const driver_device_config_base &config)
		: driver_device(machine, config) { }

	/* memory pointers */
	UINT8 *        videoram;
	UINT8 *        colorram;
	UINT8 *        spriteram;
	UINT8 *        spriteram_2;
	UINT8 *        spritebank;
	UINT8 *        scroll;
	size_t         spriteram_size;

	/* video-related */
	tilemap_t        *bg_tilemap;

	/* sound-related */
	UINT8          sn_latch;

	/* devices */
	cpu_device *audiocpu;
	running_device *sn1;
	running_device *sn2;
	running_device *dac;
	running_device *discrete;
};


/*----------- defined in video/circusc.c -----------*/

WRITE8_HANDLER( circusc_videoram_w );
WRITE8_HANDLER( circusc_colorram_w );

VIDEO_START( circusc );
WRITE8_HANDLER( circusc_flipscreen_w );
PALETTE_INIT( circusc );
VIDEO_UPDATE( circusc );
