NAME	:=	PmergeMe

#################
### COMPILERS ###
#################

# C++ compilers	:	gcc, c++
CXX			:=	c++
# Flags
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -MMD -MP
# Debug flags
CXXFLAGS	+=	-g3 -O0

# Include flags
IFLAGS	=	-I$(INC_DIR)

CLANG_TIDY_FLAGS	:=	\
						bugprone-*, \
						cppcoreguidelines-*, \
						-cppcoreguidelines-pro-bounds-pointer-arithmetic, \
						google-*, \
						clang-analyzer-*, \
						readability-*, \
						misc-*

######################
### PROJECT LAYOUT ###
######################

BUI_DIR	:=	build/
INC_DIR	:=	include/
SRC_DIR	:=	src/

###############
### SOURCES ###
###############

SRC_FIL	=	main \
			fj \
			PmergeMe

SRC	=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FIL)))
OBJ	=	$(addprefix $(BUI_DIR), $(addsuffix .o, $(SRC_FIL)))


###############
### RECIPES ###
###############

all:	$(NAME)

$(NAME): $(OBJ)
	@$(call link_and_test,$(CXX) $^ -o $@)

$(BUI_DIR)%.o:	$(SRC_DIR)%.cpp | $(BUI_DIR)
	@mkdir -p $(@D)
	@$(call compile_and_test,$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@)

$(BUI_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUI_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf .clangd .clang-tidy

re:	fclean all

dev: .clangd .clang-tidy tags

.clangd: Makefile
	@echo "Generating .clangd config"
	@echo "CompileFlags:" > .clangd
	@echo "  Add:" >> .clangd
	@for flag in $(CFLAGS); do \
		echo "    - '$$flag'" >> .clangd; \
	done
	@for dir in $(INC_DIR); do \
		abs_dir=$$(realpath $$dir) ; \
		echo "    - '-I$$abs_dir'" >> .clangd ; \
	done
	@echo "[.clangd generated]"


.clang-tidy: Makefile
	@bear -- make
	@echo "Generating $@ file"
	@echo "Checks: >" > $@
	@for flag in $(CLANG_TIDY_FLAGS); do \
		echo "         $$flag" >> $@; \
	done
	@echo "WarningsAsErrors: ''" >> $@
	@echo "HeaderFilterRegex: ''" >> $@
	@echo "FormatStyle: none" >> $@
	@echo "CheckOptions:" >> $@
	@echo "  - key:     Standard" >> $@
	@echo "    value:  c++98" >> $@

# Currently tags are for C++ only
tags:
	@echo "Generating tags"
	@ctags -R --languages=C++ --c++-kinds=+cfpsv --fields=+iaS --extras=+q $(SRC_DIR) $(INC_DIR)

test:
	scan-build-12 $(MAKE) re

.PHONY: all clean fclean re .clangd .clang-tidy test

-include: $(OBJ:.o=.d)

#######################
### TERMINAL COLORS ###
#######################

NO_COLOR		:=	\033[m
ERROR_COLOR		:=	\033[0;31m
OK_COLOR		:=	\033[0;32m
LIN_COLOR		:=	\033[0;33m
COM_COLOR		:=	\033[0;34m
EXE_COLOR		:=	\033[0;35m
OBJ_COLOR		:=	\033[0;36m
WARN_COLOR		:=	\033[0;33m

######################
### OUTPUT STRINGS ###
######################

OK_STRING		:=	[OK]
ERROR_STRING	:=	[ERROR]
WARN_STRING		:=	[WARNING]
COM_STRING		:=	Compiling
LIN_STRING		:=	Linking

#################
### FUNCTIONS ###
#################

define link_and_test
printf "%b" "$(LIN_COLOR)$(LIN_STRING) $(EXE_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(LIN_COLOR)$(LIN_STRING)$(EXE_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(LIN_COLOR)$(LIN_STRING)$(EXE_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(LIN_COLOR)$(LIN_STRING)$(EXE_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

define compile_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef
