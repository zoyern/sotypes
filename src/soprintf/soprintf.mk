# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    soprintf.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 02:15:59 by marvin            #+#    #+#              #
#    Updated: 2024/09/26 21:15:59 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOPRINTF_DIR		=	soprintf

SOPRINTF_HEADER		=	soprintf.h
SOPRINTF_FILE		=	soprintf.c soprintf_nbr.c soprintf_c.c\
						soprintf_color.c

SOPRINTF			=	$(addprefix $(SOPRINTF_DIR)/, $(SOPRINTF_FILE))
SOPRINTF_HEAD		=	$(addprefix $(SOPRINTF_DIR)/, $(SOPRINTF_HEADER))