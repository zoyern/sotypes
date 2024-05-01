# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    soprintf.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 02:15:59 by marvin            #+#    #+#              #
#    Updated: 2024/05/01 05:34:02 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOPRINTF_DIR		=	soprintf

SOPRINTF_HEADER		=	soprintf.h
SOPRINTF_FILE		=	soprintf.c soprintf_nbr.c soprintf_c.c\
						soprintf_ansi.c soprintf_ansi_utils.c soprintf_ansi_rgb.c\
						soprintf_ansi_convert.c soprintf_color.c

SOPRINTF			=	$(addprefix $(SOPRINTF_DIR)/, $(SOPRINTF_FILE))
SOPRINTF_HEAD		=	$(addprefix $(SOPRINTF_DIR)/, $(SOPRINTF_HEADER))