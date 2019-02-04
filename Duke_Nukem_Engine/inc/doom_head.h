/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_head.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:28:45 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 21:18:20 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_HEAD_H
# define DOOM_HEAD_H

# include "../Library/libft/libft.h"

# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include "SDL_net.h"

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>

# include "doom_struct.h"
# include "get_next_line.h"

# define OVLP(a0,a1,b0,b1) (min(a0,a1)<=max(b0,b1)&&min(b0,b1)<=max(a0,a1))
# define INTERSECTBOX(a,b,c,d,e,f,g,h) (OVLP(a,c,e,g)&&OVLP(b,d,f,h))
# define NORM is_it_norm_other(data, str) == 0

void			unload_data(t_main_data *main);
void			sdl_start_protocols(t_main_data *main);
void			prog_quit(int flag, t_main_data *main);
int				load_image_png(t_main_data *main, int tex_arr_num, char *path);
void			loop_preparations(t_main_data *main);
Mix_Music		*load_music(char *path);
int				load_all_sounds(t_main_data *main);
void			load_textures(t_main_data *main);
void			init_backup_framer(t_main_data *main);
SDL_Surface		*load_png_picture(char *path);

int				init_fonts(t_main_data *main, char *font_path, int font_size);
t_text			set_txt(int x, int y, SDL_Color color, int font_size);
int				draw_text(t_main_data *main, char *text,
t_text txt, char *font_path);

void			ingame_mechanics(t_main_data *main);
void			render_mechanics(t_main_data *main);

void			draw_screen(t_main_data *main);
void			draw_screen_init(t_main_data *main, int *renderedsectors);
t_coord3		set_point(int a, int b, int c);
void			vline(t_main_data *main, t_coord3 borders, t_coord3 colors);
void			vline_tex(t_main_data *main, t_coord3 borders, int tex_num);
void			player_view_calc(t_main_data *main);
void			wall_intersections(t_main_data *main);
void			perspective_transformation(t_main_data *main);
void			floor_ceil_views(t_main_data *main);
void			project_heights(t_main_data *main);
void			draw_floor_ceil(t_main_data *main);
void			draw_walls(t_main_data *main);
void			sched_neighbor(t_main_data *main);
void			texture_entire_wall(t_main_data *main);
float			yaw(t_main_data *main, float y, float z);
void			texture_floor(t_main_data *main);
void			texture_ceil(t_main_data *main);
void			texture_wall(t_main_data *main);
int				draw_wall_textures(t_main_data *main);
void			draw_previous_frame(t_main_data *main);
void			save_current_frame(t_main_data *main);

int				load_skybox_pix(t_main_data *main, char *path);
void			draw_skybox(t_main_data *main);
int				pixel_bright(int pixel_color, float change);

void			draw_minimap(t_main_data *main);
void			draw_vectors(t_main_data *main);
int				ft_draw_line(t_main_data *main, t_coord start,
t_coord end, int color);
void			draw_player_info(t_main_data *main);
void			draw_flying_info(t_main_data *main);
void			draw_hud(t_main_data *main);
void			draw_inventory_short(t_main_data *main);
void			draw_inventory(t_main_data *main, SDL_Color color, int y);
void			draw_lift_stuff(t_main_data *main);
int				load_helmet(t_main_data *main);
void			draw_helmet(t_main_data *main);
void			load_weapons(t_main_data *main);
void			draw_weapons(t_main_data *main);
int				load_pistol_sprite(t_main_data *main, int sprite);
void			draw_pistol_animation(t_main_data *main);
int				load_shotgun_sprite(t_main_data *main, int sprite);
void			draw_shotgun_animation(t_main_data *main);
void			draw_pistol(t_main_data *main, int x_pos,
int y_pos, int sprite);

int				upload_items(t_main_data *main, int item_num, char *path);
int				upload_cards(t_main_data *main, int card_num, char *path);
int				load_items(t_main_data *main);
int				sprite_loading(t_main_data *main);
void			sprite_analyzing(t_main_data *main);
void			draw_sprites(t_main_data *main);
void			vline_card(t_main_data *main, int x, int tex_num);
void			vline_item(t_main_data *main, int x, int tex_num);
void			find_sprite_end(t_main_data *main, float dist);
void			find_sprite_visual(t_main_data *main, float dist);
void			transformation_formulas(t_main_data *main);
int				calc_sprite_interactions(t_main_data *main);
int				calc_sprite_view(t_main_data *main);
void			draw_key_sprite(t_main_data *main, int key);
void			draw_item_sprite(t_main_data *main, int item);
void			draw_imp_stuff(t_main_data *main);

void			move_player(t_main_data *main, float dx, float dy);
void			mouse_aim(t_main_data *main);
void			physic_behavior(t_main_data *main);
void			vertical_collision(t_main_data *main);
void			horizontal_collision(t_main_data *main, float dx,
float dy, size_t s);
void			fly_mode(t_main_data *main);
int				on_segment(t_vec2 p, t_vec2 q, t_vec2 r);
int				orientation(t_vec2 p, t_vec2 q, t_vec2 r);
int				stat_intersect(t_vec2 p1, t_vec2 q1, t_vec2 p2, t_vec2 q2);
int				point_inside(t_vec2 *vertex, Uint32 npoints,
t_vec2 point, int flag);
int				point_on_map(t_main_data *main);
int				calc_damage(t_main_data *main);
void			you_died(t_main_data *main);

void			interact_doors(t_main_data *main);
void			check_doors(t_main_data *main);

void			interact_lifts(t_main_data *main);
void			check_lifts(t_main_data *main, unsigned int i);

void			key_behavior(t_main_data *main);
void			mouse_behavior(t_main_data *main, SDL_Event event);

void			init_start(t_main_data *main);
void			sdl_quit(t_main_data *main, int e);
void			my_error(char *c);

float			clamp(float a, float mi, float ma);
float			min(float a, float b);
float			max(float a, float b);
float			vxs(float x0, float y0, float x1, float y1);
t_vec2			intersect(t_vec3 cr1, t_vec3 cr2, float x4, float y4);
float			pointside(t_vec3 cr1, float y0, float x1, float y1);

float			ft_map(float num, float sr_start, t_vec3 funk);
t_vec3			ft_map_help(float sr_end, float dst_start, float dst_end);

void			find_pink_msg(t_main_data *main);
void			start_a_game(t_main_data *main);

void			texture_checks(t_main_data *main);

void			parser(t_data *data, t_main_data *main);
void			ft_error1(char *str);
char			*ft_joinfree(char *s1, char *s2, int j);
int				len_of_array(char **str);
void			init_count(t_data *data);
void			count_all(t_data *data, char **reading);
void			second_checking(t_data *data, char **str);
int				is_it_digit(char *str);
int				len_of_array(char **str);
int				is_it_norm(t_data *data, char **str);

void			write_parsed_data(t_main_data *main, t_data *data,
char **reading);
void			parser_write_additional(t_main_data *main, t_data *data,
char **reading);
int				*ft_intsplit(char const *s, char c);
void			ft_intdel(int **del);
void			parse_find_items(t_main_data *main, char **reading,
int y, int *sec_sprites);
void			parse_find_enemy(t_main_data *main, char **reading,
int y, int *sec_sprites);
void			parse_find_key(t_main_data *main, char **reading,
int y, int *sec_sprites);

int				menu(t_main_data *main, t_data *data);
SDL_Surface		*load_image(char *path);
int				go(t_main_data *main, t_data *data);
void			draw_menu(t_main_data *main);
void			render_mechanics(t_main_data *main);
void			pos_enemy(t_main_data *main);

#endif
