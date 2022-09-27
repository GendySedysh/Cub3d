/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:35:16 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/27 15:11:13 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARCER_H
# define MAP_PARCER_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define BUFFER_SIZE 10
# define SCALE 32
# define SPEED 3
# define STRAFE_SPEED 3.0
# define ROTATE_SPEED 2.0
# define M_PI 3.14159265358979323846
# define FOV 60

typedef struct s_parser_control
{
	int			resolution;
	int			npath;
	int			spath;
	int			wpath;
	int			epath;
	int			sprite;
	int			ceiling;
	int			floor;
}				t_parser_control;

typedef struct s_ray
{
	int			flag;
	int			num_of_sprites;
	double		sprite_len;
	double		len;
	double		x_ray;
	double		y_ray;
	double		angle;
	double		s;
}				t_ray;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef struct s_player
{
	int			x;
	int			y;
	double		pov;
}				t_player;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct s_sprite
{
	int				x;
	int				y;
	struct s_sprite	*next;
}				t_sprite;

typedef struct s_map
{
	int					width;
	int					height;
	char				*npath;
	char				*spath;
	char				*wpath;
	char				*epath;
	char				*sprite;
	t_color				ceiling;
	t_color				floor;
	int					str_num;
	char				**map;
	t_sprite			*sprite_data;
	int					sprite_num;
	int					bmp_flag;
	int					pacer_size;
	t_parser_control	parser_control;
}				t_map;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_keys		keys;
	t_map		map_data;
	t_player	player;
	t_data		texture1;
	t_data		texture2;
	t_data		texture3;
	t_data		texture4;
	t_data		sprite;
	t_sprite	*sprite_list;
	t_data		img;
}				t_vars;

size_t			ft_strlen(const char *s);
int				next_line_char(char *str);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*str_join(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);
int				my_isprint(int c);
int				my_isdigit(int c);
int				my_atoi(char *nptr);
int				ft_intlen(int num);
int				have_char(char *str, char c);
int				ft_strcompare(char *str1, char *str2);
char			*ft_strdup(char *s);
t_map			get_resolution(t_map map, char *line);
t_color			get_color(t_color color, char *line);
char			*get_texture_path(char *line);
int				map_ext_cmp(const char *s1, const char *s2, int i);
t_map			map_read(const char *map_path);
t_map			fill_map_settings(char *line, t_map	map_settings);
int				map_parcer_feedback(char *line);
t_map			parce_map_settings(char *line, t_map map_settings, int fd);
t_map			get_sprite_data(t_map map);
t_map			put_sprite_on_map(t_map map);
t_sprite		*ft_create_elem(int x, int y);
void			ft_list_push_front(t_sprite **begin_list, int x, int y);
t_sprite		*sort(t_sprite *root);
t_map			map_scale(t_map map_data);
void			free_map(t_map m_d);
t_player		get_start_data(t_map m_d);
void			texture_init(t_vars *vars);
void			raycast(t_data img, t_vars *vars, double angle, int x);
void			render_texture(t_data img, t_ray ray, t_vars *vars, int x);
int				ray_caster(t_vars *vars);
t_data			my_mlx_new_image(void *mlx, int width, int height);
unsigned int	color_convert(t_color input_color);
t_ray			cast_ray(t_vars *vars, double angle);
void			render_ray(t_data img, t_vars *vars, t_ray ray, int x);
void			multiple_raycasting(t_data img, t_vars *vars);
t_ray			flag_for_ray(t_ray ray, t_vars *vars);
int				get_pixel_color(int x, int y, t_data *img);
void			close_win(t_vars *vars);
void			texture_init(t_vars *vars);
void			render_sprite(t_data img, t_vars *vars);
int				exit_normally(t_vars *vars);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
void			move(t_vars *vars);
void			pic_export(t_vars *vars);
void			render_screenshot(t_vars *vars);
t_ray			ray_init(void);
t_map			map_parcer_init(void);
t_color			color_init(void);
t_player		player_init(void);
t_keys			keys_init(void);
t_vars			vars_init(void);
t_data			data_init(void);
t_sprite		sprite_init(void);
int				save_check(char *str);
int				ext_check(char *str);
void			parcer_free(t_map vars);
int				exit_with_error(char *str, t_vars *vars, int flag);
int				map_valid_check(t_map map_data);
void			parser_valid_check(t_map map_data);
int				perror_and_exit(char *str);
int				nswe_check(char c);
void			delete_list(t_sprite *head);
int				parcer_check(char c);
int				string_check(char c);
int				map_char_check(char c);
int				parser_fill_check(t_map map_data);
void			map_chars_check(t_map map_data, int i, int j);
int				paser_free_and_exit(char *str, t_map map_data);
void			alien_char_search(char *line, t_map map_settings);
#endif