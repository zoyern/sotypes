# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 18:55:59 by marvin            #+#    #+#              #
#    Updated: 2024/10/22 17:42:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include $(CURDIR)/src/somemory/somemory.mk
include $(CURDIR)/src/soenv/soenv.mk
include $(CURDIR)/src/soprintf/soprintf.mk
include $(CURDIR)/src/solib_utils/solib_utils.mk
include $(CURDIR)/src/sotask/sotask.mk

SRC_DIR		= $(CURDIR)/src

LIB_HEADER	= $(addprefix $(SRC_DIR)/, sotypes.h)
SRC_HEADER	= sotypes_t.h all.h
SRC_FILES	= sotypes.c

DIR			+= $(SOMEMORY_DIR)
DIR			+= $(SOENV_DIR)
DIR			+= $(SOPRINTF_DIR)
DIR			+= $(SOLIB_UTILS_DIR)
DIR			+= $(SOTASK_DIR)

SRC_HEADER	+= $(SOMEMORY_HEAD)
SRC_HEADER	+= $(SOENV_HEAD)
SRC_HEADER	+= $(SOPRINTF_HEAD)
SRC_HEADER	+= $(SOLIB_UTILS_HEAD)
SRC_HEADER	+= $(SOTASK_HEAD)

SRC_FILES	+= $(SOMEMORY)
SRC_FILES	+= $(SOENV)
SRC_FILES	+= $(SOPRINTF)
SRC_FILES	+= $(SOLIB_UTILS)
SRC_FILES	+= $(SOTASK)

HEADERS		= $(addprefix $(SRC_DIR)/, $(SRC_HEADER))
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
FOLDERS		= $(addprefix $(SRC_DIR)/, $(DIR))
FOLDERS		+= $(SRC_DIR)
