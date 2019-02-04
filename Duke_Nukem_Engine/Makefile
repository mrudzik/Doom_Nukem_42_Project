# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 14:03:42 by mrudzik           #+#    #+#              #
#    Updated: 2019/01/09 20:55:18 by mrudzik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

SRC_DIR :=	./src/
OBJ_DIR :=	./obj/
INC_DIR :=	./inc/
LIB_DIR :=	./Library/

SRC = 	main.c 					sdl_protocols.c 		\
		syst_stuff.c 			load_image_png.c 		load_data.c 		\
		font_stuff.c 			\
		init.c 					exit.c 					\
		standart.c				standart_2.c 			\
		player_collision.c 		point_inside.c 			point_math.c 		\
		player_actions.c 		damage.c 				\
		draw_screen.c 			draw_screen_calcs.c 	draw_screen_calcs2.c\
		draw_screen_calcs3.c 	draw_screen_calcs4.c 	draw_screen_save.c 	\
		draw_screen_textures.c 	\
		draw_sprites.c 			draw_sprites_calc.c 	draw_sprites_items.c\
		draw_sprites_enemy.c	\
		sprite_processing.c 	\
		draw_minimap.c 			draw_vectors.c 			ft_draw_line.c 		\
		draw_hud.c 				draw_hud_2.c 			draw_info.c 		\
		draw_weapons.c 			draw_weapon_animation.c load_weapons.c   	\
		load_items.c 			\
		draw_items.c  			draw_items_2.c 			draw_items_3.c 		\
		draw_skybox.c 			enemy_pos.c\
		draw_wall_textures.c 	\
		key_behavior.c 			mouse_behavior.c 		\
		testing.c 				mechanics.c 			\
		doors.c 				lifts.c 				\
		parser_vadim.c 			parser_first_checking.c	parser_second_check.c\
		parser_first_help.c 	\
		parser_write_data.c 	parser_write_additional.c 						\
		parser_write_sprites.c 	\
		ft_intsplit.c 			get_next_line.c  		\
		menu.c 					menu_help.c
		
		#parser.c 			
		#parser_start.c 			parser_help1.c 			parser_write.c	
		#yur_strjoin_free.c			yur_strsplit2.c 

#	project object files
OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#	libraries
#libft
LIBFT = 		$(LIBFT_DIR)libft.a
LIBFT_DIR :=	$(LIB_DIR)libft/
LIBFT_FLAGS := 	-lft -L $(LIBFT_DIR)

# SDL_FLAGS	=	-I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks
INCLUDES	=	-I $(INC_DIR)\
				-I ./frameworks/SDL2.framework/Versions/A/Headers \
				-I ./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I ./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I ./frameworks/SDL2_mixer.framework/Headers \
				-I ./frameworks/SDL2_net.framework/Headers \
				-F ./frameworks 
				
# OGL_FLAGS	=	-framework OpenGL -framework AppKit
FRAMEWORKS	=	-F ./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer -framework SDL2_net

# SDL_FRM = -framework SDL2 -F /Library/Frameworks/ ./SDL2_ttf/SDL2_ttf

# SDL_INC = -I /Library/Frameworks/SDL2.framework/Headers/ -I SDL_ttf/

LINK_FLAGS := $(LIBFT_FLAGS)
CC_FLAGS := -Wall -Wextra -Werror -O3

all:
	make -C $(LIBFT_DIR)
	make $(NAME)

# compiles .c files
$(NAME): $(LIBFT) $(OBJ) $(INC_DIR)
	gcc $(OBJ) $(LINK_FLAGS) -o $(NAME) $(INCLUDES) $(FRAMEWORKS) #-g -fsanitize=address
	@ echo "\n===> doom-nukem compiled\n"

#compiles .o files
$(OBJ_DIR)%.o: %.c
	gcc -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS) $(INCLUDES)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)

re: fclean all

vpath %.c $(SRC_DIR)
