# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 18:55:59 by marvin            #+#    #+#              #
#    Updated: 2024/04/25 21:08:42 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include $(CURDIR)/src/somemory/somemory.mk

SRC_DIR		= $(CURDIR)/src

DIR			= $(SOMEMORY_DIR)

LIB_HEADER	= $(addprefix $(SRC_DIR)/, sotypes.h)

SRC_HEADER	=  types.h all.h

SRC_FILES	= sotypes.c

SRC_HEADER	+= $(SOMEMORY_HEAD)

SRC_FILES	+= $(SOMEMORY)

HEADERS		= $(addprefix $(SRC_DIR)/, $(SRC_HEADER))
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
FOLDERS		= $(addprefix $(SRC_DIR)/, $(DIR))
FOLDERS		+= $(SRC_DIR)
