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

SOENV_DIR		=	soenv

SOENV_HEADER	=	soenv.h
SOENV_FILE		=	soenv.c

SOENV			=	$(addprefix $(SOENV_DIR)/, $(SOENV_FILE))
SOENV_HEAD		=	$(addprefix $(SOENV_DIR)/, $(SOENV_HEADER))