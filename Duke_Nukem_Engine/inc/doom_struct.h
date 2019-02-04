/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:21:42 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 20:43:06 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_STRUCT_H
# define DOOM_STRUCT_H

# include "doom_head.h"

# define W 			1200
# define H 			800
# define SKY_W		4320
# define SKY_H 		2143
# define MAX_QUEUE 	32
# define INF 		100000
# define TEX_LEN 	2
# define TEX_H 		128
# define TEX_W 		128
# define TEX_COUNT 	20
# define SKY_GLASS 	4

# define F_ARIAL 	"fonts/ARIAL.TTF"
# define F_MORPHEUS 	"fonts/MORPHEUS.TTF"
# define F_DIGITAL 	"fonts/auto_digital.TTF"

# define MAX_SPRITES	5
# define PISTOL_PIC 	128
# define SHOTGUN_PIC	178
# define CARD_W 		42
# define CARD_H			48
# define ITEM_W 		100
# define ITEM_H 		100
# define YELLOW_KEY 0
# define RED_KEY 	1
# define GREEN_KEY 	2
# define MEDPACK 	3
# define AMMO 		4
# define ARMOR 		5
# define IMP 		6

# define DOOR_OPENED  	1
# define DOOR_OPENING 	3
# define DOOR_CLOSED 	2
# define DOOR_CLOSING 	4
# define DOOR_SPEED 	0.5

# define LIFT_DOWN  	1
# define LIFT_FALLING	3
# define LIFT_UP 		2
# define LIFT_RAISING 	4
# define LIFT_SPEED 	0.5

# define EYEHEIGHT  	6
# define DUCKHEIGHT 	2.5
# define HEADMARGIN 	1
# define KNEEHEIGHT 	2
# define HFOV 			(0.73f * H)
# define VFOV			(0.2f * H)

# define GM 	main->game
# define DR 	main->draw
# define DRI 	main->draw.init
# define DRM 	main->draw.math
# define DRS 	main->draw.sprite
# define PD 	main->player
# define SD 	main->sectors
# define MF 	main->fonts
# define MM  	main->menu
# define KEY 	event.key.keysym.sym
# define EXIT 	(event.type == SDL_KEYDOWN && KEY == SDLK_ESCAPE)

typedef struct		s_vec2
{
	float	x;
	float	y;
}					t_vec2;

typedef struct		s_vec3
{
	float	x;
	float	y;
	float	z;
}					t_vec3;

typedef struct		s_coord
{
	int x;
	int y;
}					t_coord;

typedef struct		s_coord3
{
	int x;
	int y;
	int z;
}					t_coord3;

typedef struct		s_item
{
	int		sectorno;
	int		sx1;
	int		sx2;
}					t_item;

typedef struct		s_text
{
	int			size;
	t_coord		pos;
	SDL_Color	color;
}					t_text;

typedef struct		s_thing
{
	t_vec2		position;
	int			sprite_id;
	int			sprite_width;
	int			sprite_heigh;
	float		sprite_w;
	float		sprite_floor;
	float		sprite_ceil;
}					t_thing;

typedef struct		s_sector
{
	signed char		*neighbors;
	unsigned		npoints;
	int				end;
	int				light;
	int				door;
	int				lift;
	int				texture_num;
	float			start_floor;
	float			start_ceil;
	float			floor;
	float			ceil;
	t_vec2			*vertex;
	t_thing			*things;
}					t_sector;

typedef struct		s_game_data
{
	int		window_modes;
	int		doors_pending;
	int		lifts_pending;
	int		ground;
	int		falling;
	int		moving;
	int		ducking;
	int		pushing;
	int		flying;
	int		x_m;
	int		y_m;
	float	pl_speed;
	float	yaw;
	float	eyeheight;
	float	move_vec[2];
}					t_game_data;

typedef struct		s_inventory
{
	int		hp;
	int		armor;
	int		ammo;
	int		weapon_type;
	int		weapon_must_hit;
	int		red_key;
	int		yellow_key;
	int		green_key;
	float	weapon_phase;
}					t_inventory;

typedef struct		s_player_data
{
	float			angle;
	float			anglesin;
	float			anglecos;
	float			yaw;
	t_vec3			where;
	t_vec3			velocity;
	Uint32			sector;
	t_inventory		inventory;
}					t_player_data;

typedef struct		s_draw_math
{
	int			x1;
	int			x2;
	int			neighbor;
	int			y1_a;
	int			y1_b;
	int			y2_a;
	int			y2_b;
	int			ny1_a;
	int			ny1_b;
	int			ny2_a;
	int			ny2_b;
	int			begin_x;
	int			end_x;
	int			x;
	int			z;
	int			y_a;
	int			cy_a;
	int			y_b;
	int			cy_b;
	int			flor_ceil;
	int			u;
	int			v;
	int			x1_edge;
	int			x2_edge;
	int			begin_x_local;
	int			end_x_local;
	int			ny_a;
	int			cny_a;
	int			ny_b;
	int			cny_b;
	Uint32		r1;
	Uint32		r2;
	Uint32		r;
	float		y_ceil;
	float		y_floor;
	float		ny_ceil;
	float		ny_floor;
	float		vx1;
	float		vx2;
	float		vy1;
	float		vy2;
	float		pcos;
	float		psin;
	float		tx1;
	float		tx2;
	float		tz1;
	float		tz2;
	float		near_z;
	float		near_side;
	float		far_z;
	float		far_side;
	float		x_scale1;
	float		y_scale1;
	float		x_scale2;
	float		y_scale2;
	float		vx3;
	float		vy3;
	float		full_len;
	float		len;
	float		vx_start;
	float		vx_end;
	float		vy_start;
	float		vy_end;
	t_vec2		i1;
	t_vec2		i2;
	t_item		now;
	t_sector	*sect;
}					t_draw_math;

typedef struct		s_sprite_math
{
	int		begin_x_room;
	int		end_x_room;
	int		spr_num;
	int		y1;
	int		y2;
	float	dist;
	float	vx1_spr;
	float	vy1_spr;
	float	vx2_spr;
	float	vy2_spr;
}					t_sprite_math;

typedef struct		s_draw_init
{
	Uint32	n;
	Uint32	s;
	int		x;
	int		qu;
	int		wal;
	int		windows;
}					t_draw_init;

typedef struct		s_draw_data
{
	Uint32			num_sectors;
	int				y_top[W];
	int				y_bottom[W];
	int				img_buff[H][W];
	int				**saved_img_buff;
	int				**textures;
	int				**helmet;
	int				**skybox_pix;
	int				***card;
	int				***item;
	int				***pistol;
	int				***shotgun;
	t_item			queue[MAX_QUEUE];
	t_item			*head;
	t_item			*tail;
	t_draw_init		init;
	t_draw_math		math;
	t_sprite_math	sprite;
	SDL_Surface		*sky_box;
}					t_draw_data;

typedef struct		s_font_data
{
	SDL_Surface		*font_surf;
	SDL_Texture		*font_textr;
	TTF_Font		*font_ttf;
	SDL_Rect		font_rect;
}					t_font_data;

typedef struct		s_menu
{
	SDL_Surface		*menu;
	int				num_menu;
	int				flag;
	char			*str[3];
	SDL_Color		m_color;
}					t_menu;

typedef struct		s_data
{
	char			*name;
	int				fd;
	int				count_vert;
	int				count_sector;
	int				count_play;
	int				count_key;
	int				count_ammun;
	int				count_door;
	int				count_lift;
	int				count_end;
	int				count_enemy;
	int				count_text;
	int				size_vert;
}					t_data;

typedef struct		s_main_data
{
	int				dev_mode;
	int				time;
	int				flag;
	int				obj;
	int				kills;
	double			a;
	double			b;
	double			c;
	int				r;
	int				sqrt_discr;
	const Uint8		*key_state;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_game_data		game;
	t_draw_data		draw;
	t_player_data	player;
	t_sector		*sectors;
	t_font_data		fonts;
	t_menu			menu;
	Mix_Music		*mus;
	Mix_Chunk		*guns[2];
	Mix_Music		*mus2;
}					t_main_data;

typedef struct		s_brez
{
	int a;
	int b;
	int sign_a;
	int sign_b;
	int f;
	int x;
	int y;
	int end_x;
	int end_y;
}					t_brez;

#endif
