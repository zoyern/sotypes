# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    soenv.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 02:15:59 by marvin            #+#    #+#              #
#    Updated: 2024/04/30 18:08:49 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOLIB_UTILS_DIR		=	solib_utils

SOLIB_UTILS_HEADER	=	solib_utils.h
SOLIB_UTILS_FILE		=	solib_utils.c solib_utils2.c solib_utils_convert.c

SOLIB_UTILS			=	$(addprefix $(SOLIB_UTILS_DIR)/, $(SOLIB_UTILS_FILE))
SOLIB_UTILS_HEAD		=	$(addprefix $(SOLIB_UTILS_DIR)/, $(SOLIB_UTILS_HEADER))