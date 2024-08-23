#only test invalid maps

valgrind ./cub3D maps/invalidmap_direct_2xpm.cub
valgrind ./cub3D maps/invalidmap_doubledirect.cub
valgrind ./cub3D maps/invalidmap_dupplayer.cub
valgrind ./cub3D maps/invalidmap_elementdup.cub
valgrind ./cub3D maps/invalidmap_empty.cub
valgrind ./cub3D maps/invalidmap_minus.cub
valgrind ./cub3D maps/invalidmap_newline.cub
valgrind ./cub3D maps/invalidmap_noplayer.cub
valgrind ./cub3D maps/invalidmap_noplayer.cub
valgrind ./cub3D maps/invalidmap_space.cub
valgrind ./cub3D maps/invalidmap.cbu
valgrind ./cub3D maps/invalidmap_nowall_left.cub
valgrind ./cub3D maps/invalidmap_nowall_right.cub
valgrind ./cub3D maps/invalidmap_nowall_top.cub
valgrind ./cub3D maps/invalidmap_nowall_bottom.cub
valgrind ./cub3D .cub
valgrind ./cub3D a.cub.cub
valgrind ./cub3D cub
