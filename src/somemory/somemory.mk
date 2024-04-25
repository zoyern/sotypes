# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    somemory.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 02:15:59 by marvin            #+#    #+#              #
#    Updated: 2024/04/25 19:24:37 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOMEMORY_DIR		=	somemory

SOMEMORY_HEADER		=	somemory.h
SOMEMORY_FILE		=	somemory.c sofree.c somalloc.c \
						somemory_add.c somemory_clear.c somemory_find.c \
						somemory_show.c

SOMEMORY			=	$(addprefix $(SOMEMORY_DIR)/, $(SOMEMORY_FILE))
SOMEMORY_HEAD		=	$(addprefix $(SOMEMORY_DIR)/, $(SOMEMORY_HEADER))