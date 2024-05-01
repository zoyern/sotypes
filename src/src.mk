# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 18:55:59 by marvin            #+#    #+#              #
#    Updated: 2024/04/30 19:43:42 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include $(CURDIR)/src/somemory/somemory.mk
include $(CURDIR)/src/soenv/soenv.mk
include $(CURDIR)/src/soprintf/soprintf.mk

SRC_DIR		= $(CURDIR)/src

LIB_HEADER	= $(addprefix $(SRC_DIR)/, sotypes.h)
SRC_HEADER	= types.h all.h
SRC_FILES	= sotypes.c

DIR			+= $(SOMEMORY_DIR)
DIR			+= $(SOENV_DIR)
DIR			+= $(SOPRINTF_DIR)

SRC_HEADER	+= $(SOMEMORY_HEAD)
SRC_HEADER	+= $(SOENV_HEAD)
SRC_HEADER	+= $(SOPRINTF_HEAD)

SRC_FILES	+= $(SOMEMORY)
SRC_FILES	+= $(SOENV)
SRC_FILES	+= $(SOPRINTF)

HEADERS		= $(addprefix $(SRC_DIR)/, $(SRC_HEADER))
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
FOLDERS		= $(addprefix $(SRC_DIR)/, $(DIR))
FOLDERS		+= $(SRC_DIR)
