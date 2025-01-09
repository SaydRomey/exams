
# 🎯 Default 'make' target
.DEFAULT_GOAL	:= all

# 🛠️ Handle invalid targets
.DEFAULT:
	$(info make: *** No rule to make target '$(MAKECMDGOALS)'.  Stop.)
	@$(MAKE) help --no-print-directory

# 👤 Author and Build Configuration
AUTHOR	:= cdumais
COMPILE	:= c++
C_FLAGS	:= -Wall -Wextra -Werror -std=c++98
REMOVE	:= rm -rf
MKDIR	:= mkdir -p

# 🎨 Colors and Style with ANSI
ESC			:= \033
RESET		:= $(ESC)[0m
BOLD		:= $(ESC)[1m
ITALIC		:= $(ESC)[3m
UNDERLINE	:= $(ESC)[4m
RED			:= $(ESC)[91m
GREEN		:= $(ESC)[32m
YELLOW		:= $(ESC)[93m
ORANGE		:= $(ESC)[38;5;208m
BLUE		:= $(ESC)[94m
PURPLE		:= $(ESC)[95m
CYAN		:= $(ESC)[96m
GRAYTALIC	:= $(ESC)[3;90m
UP			:= $(ESC)[A
ERASE_LINE	:= $(ESC)[2K

# 🎯 Standardized Output Macros
INFO		= echo "[$(BOLD)$(PURPLE)$(1)$(RESET)]\t$(ORANGE)$(2)$(RESET)$(GRAYTALIC)$(3)$(RESET)"
SUCCESS		= echo "[$(BOLD)$(PURPLE)$(1)$(RESET)]\t$(GREEN)$(2)$(RESET)"
WARNING		= echo "[$(BOLD)$(PURPLE)$(1)$(RESET)]\t$(YELLOW)$(2)$(RESET)"
ERROR		= echo "❌ Error: $(1) $(RED)$(2)$(RESET)"

# 📂 Directories
MODULE00_DIR := 00/
MODULE01_DIR := 01/
MODULE02_DIR := 02/

# 🗂️ Object Directories
MODULE00_OBJ_DIR := $(MODULE00_DIR)obj/
MODULE01_OBJ_DIR := $(MODULE01_DIR)obj/
MODULE02_OBJ_DIR := $(MODULE02_DIR)obj/

# 📄 Source Files
MODULE00_SRC := Warlock.cpp main.cpp
MODULE01_SRC := Warlock.cpp ASpell.cpp ATarget.cpp Fwoosh.cpp Dummy.cpp main.cpp
MODULE02_SRC := Warlock.cpp ASpell.cpp ATarget.cpp Fwoosh.cpp Dummy.cpp Fireball.cpp \
			    Polymorph.cpp BrickWall.cpp SpellBook.cpp TargetGenerator.cpp main.cpp

# 📄 Add prefixes to source files
MODULE00_SRC := $(addprefix $(MODULE00_DIR), $(MODULE00_SRC))
MODULE01_SRC := $(addprefix $(MODULE01_DIR), $(MODULE01_SRC))
MODULE02_SRC := $(addprefix $(MODULE02_DIR), $(MODULE02_SRC))

# 🗂️ Object Files (Stored in Module-Specific obj directories)
MODULE00_OBJ := $(addprefix $(MODULE00_OBJ_DIR), $(notdir $(MODULE00_SRC:.cpp=.o)))
MODULE01_OBJ := $(addprefix $(MODULE01_OBJ_DIR), $(notdir $(MODULE01_SRC:.cpp=.o)))
MODULE02_OBJ := $(addprefix $(MODULE02_OBJ_DIR), $(notdir $(MODULE02_SRC:.cpp=.o)))

# 🚀 Executables
MODULE00 := module00
MODULE01 := module01
MODULE02 := module02

# 🧠 Subject Files
SUBJECT	:= _subject.txt
MODULE00_SUBJECT := $(MODULE00_DIR)$(SUBJECT)
MODULE01_SUBJECT := $(MODULE01_DIR)$(SUBJECT)
MODULE02_SUBJECT := $(MODULE02_DIR)$(SUBJECT)

# ==============================
##@ 🛠️  Compilation Targets
# ==============================
all: prompt_compile ## Compile Module(s) with Prompt

# 🛠️ Compilation with Prompt
prompt_compile:
	@echo "$(BOLD)Choose a module to compile:$(RESET)"
	@echo "0) 00 | 1) 01 | 2) 02 | 3) all"
	@read -p "Enter your choice: " choice; \
	case $$choice in \
		0) $(MAKE) $(MODULE00) ;; \
		1) $(MAKE) $(MODULE01) ;; \
		2) $(MAKE) $(MODULE02) ;; \
		3) $(MAKE) $(MODULE00) && $(MAKE) $(MODULE01) && $(MAKE) $(MODULE02) ;; \
		*) $(call ERROR,Invalid choice:,$$choice) ;; \
	esac

# 🛠️ Object Compilation Rules
$(MODULE00_OBJ_DIR)%.o: $(MODULE00_DIR)%.cpp
	@$(MKDIR) $(dir $@)
	@$(call INFO,$(MODULE02),Compiling...\t,$(notdir $<))
	@$(COMPILE) $(C_FLAGS) -c $< -o $@
	@printf "$(UP)$(ERASE_LINE)"

$(MODULE01_OBJ_DIR)%.o: $(MODULE01_DIR)%.cpp
	@$(MKDIR) $(dir $@)
	@$(call INFO,$(MODULE02),Compiling...\t,$(notdir $<))
	@$(COMPILE) $(C_FLAGS) -c $< -o $@
	@printf "$(UP)$(ERASE_LINE)"

$(MODULE02_OBJ_DIR)%.o: $(MODULE02_DIR)%.cpp
	@$(MKDIR) $(dir $@)
	@$(call INFO,$(MODULE02),Compiling...\t,$(notdir $<))
	@$(COMPILE) $(C_FLAGS) -c $< -o $@
	@printf "$(UP)$(ERASE_LINE)"

# 🛠️ Link Executables
$(MODULE00): $(MODULE00_OBJ)
	@$(COMPILE) $(C_FLAGS) $(MODULE00_OBJ) -o $(MODULE00)
	@$(call SUCCESS,$@,Ready!)

$(MODULE01): $(MODULE01_OBJ)
	@$(COMPILE) $(C_FLAGS) $(MODULE01_OBJ) -o $(MODULE01)
	@$(call SUCCESS,$@,Ready!)

$(MODULE02): $(MODULE02_OBJ)
	@$(COMPILE) $(C_FLAGS) $(MODULE02_OBJ) -o $(MODULE02)
	@$(call SUCCESS,$@,Ready!)

# ==============================
##@ 🚀 Execution Targets
# ==============================
run: ## Compile and Execute Module with Prompt
	@echo "$(BOLD)Choose a module to run:$(RESET)"
	@echo "0) 00 | 1) 01 | 2) 02 | 3) all"
	@read -p "Enter your choice: " choice; \
	case $$choice in \
		0) $(MAKE) $(MODULE00) && $(MAKE) run_module MODULE=$(MODULE00) ;; \
		1) $(MAKE) $(MODULE01) && $(MAKE) run_module MODULE=$(MODULE01) ;; \
		2) $(MAKE) $(MODULE02) && $(MAKE) run_module MODULE=$(MODULE02) ;; \
		3) $(MAKE) $(MODULE00) && $(MAKE) run_module MODULE=$(MODULE00); \
		   $(MAKE) $(MODULE01) && $(MAKE) run_module MODULE=$(MODULE01); \
		   $(MAKE) $(MODULE02) && $(MAKE) run_module MODULE=$(MODULE02) ;; \
		*) $(call ERROR,Invalid choice:,$$choice) ;; \
	esac

run_module:
	@$(call INFO,$(MODULE),,./$(MODULE))
	@./$(MODULE)
	@$(call SUCCESS,$(MODULE),Finished execution!\n)

# ==============================
##@ 🧹 Cleanup Targets
# ==============================
clean: ## Clean Object Files for Module(s) with Prompt
	@echo "$(BOLD)Choose a module to clean:$(RESET)"
	@echo "0) 00 | 1) 01 | 2) 02 | 3) all"
	@read -p "Enter your choice: " choice; \
	case $$choice in \
		0) $(MAKE) clean_module MODULE=$(MODULE00) OBJ_DIR="$(MODULE00_OBJ_DIR)" ;; \
		1) $(MAKE) clean_module MODULE=$(MODULE01) OBJ_DIR="$(MODULE01_OBJ_DIR)" ;; \
		2) $(MAKE) clean_module MODULE=$(MODULE02) OBJ_DIR="$(MODULE02_OBJ_DIR)" ;; \
		3) $(MAKE) clean_module MODULE=$(MODULE00) OBJ_DIR="$(MODULE00_OBJ_DIR)"; \
		   $(MAKE) clean_module MODULE=$(MODULE01) OBJ_DIR="$(MODULE01_OBJ_DIR)"; \
		   $(MAKE) clean_module MODULE=$(MODULE02) OBJ_DIR="$(MODULE02_OBJ_DIR)";; \
		*) $(call ERROR,Invalid choice:,$$choice) ;; \
	esac

clean_module:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(REMOVE) $(OBJ_DIR); \
		$(call SUCCESS,$(MODULE),Object files removed); \
	else \
		$(call WARNING,$(MODULE),No object files to remove); \
	fi

fclean: ## Clean Everything (Objects and Executables)
	@for MODULE in $(MODULE00) $(MODULE01) $(MODULE02); do \
		case $$MODULE in \
			$(MODULE00)) OBJ_DIR="$(MODULE00_OBJ_DIR)" ;; \
			$(MODULE01)) OBJ_DIR="$(MODULE01_OBJ_DIR)" ;; \
			$(MODULE02)) OBJ_DIR="$(MODULE02_OBJ_DIR)" ;; \
		esac; \
		if [ -d "$$OBJ_DIR" ]; then \
			$(REMOVE) "$$OBJ_DIR"; \
			$(call SUCCESS,$$MODULE,Object files removed); \
		else \
			$(call WARNING,$$MODULE,No object files to remove); \
		fi; \
		if [ -f "$$MODULE" ]; then \
			$(REMOVE) "$$MODULE"; \
			$(call SUCCESS,$$MODULE,Executable removed); \
		else \
			$(call WARNING,$$MODULE,No executable to remove); \
		fi; \
	done

re: fclean all ## Recompile with Prompt

# ==============================
##@ 📚 Utility Targets
# ==============================
subject: ## Show Subject for a Module
	@echo "$(BOLD)Choose a module to display its subject:$(RESET)"
	@echo "0) 00 | 1) 01 | 2) 02"
	@read -p "Enter your choice: " choice; \
	case $$choice in \
		0) [ -f $(MODULE00_SUBJECT) ] && cat $(MODULE00_SUBJECT) || $(call ERROR,Could not open file:,$(MODULE00_DIR)$(SUBJECT)) ;; \
		1) [ -f $(MODULE01_SUBJECT) ] && cat $(MODULE01_SUBJECT) || $(call ERROR,Could not open file:,$(MODULE01_DIR)$(SUBJECT)) ;; \
		2) [ -f $(MODULE02_SUBJECT) ] && cat $(MODULE02_SUBJECT) || $(call ERROR,Could not open file:,$(MODULE02_DIR)$(SUBJECT)) ;; \
		*) $(call ERROR,Invalid choice:,$$choice) ;; \
	esac

help: ## Display Available 'make' Targets
	@echo "\nAvailable targets:"
	@awk 'BEGIN {FS = ":.*##";} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "   $(CYAN)%-15s$(RESET) %s\n", $$1, $$2 \
		} \
		/^##@/ { \
			printf "\n$(GRAYTALIC)%s$(RESET)\n", substr($$0, 5) \
		}' $(MAKEFILE_LIST)


# ✅ Define .PHONY Targets
.PHONY: all prompt_compile run run_module clean clean_module fclean re subject help

# **************************************************************************** #
# 📦 Project Root
# ├── 00/
# │   ├── _subject.txt
# │   ├── Warlock.cpp
# │   ├── Warlock.hpp
# │   ├── main.cpp
# │   ├── obj/
# │   │   ├── Warlock.o
# │   │   ├── main.o
# ├── 01/
# │   ├── _subject.txt
# │   ├── Warlock.cpp
# │   ├── Warlock.hpp
# │   ├── ASpell.cpp
# │   ├── ASpell.hpp
# │   ├── ATarget.cpp
# │   ├── ATarget.hpp
# │   ├── Fwoosh.cpp
# │   ├── Fwoosh.hpp
# │   ├── Dummy.cpp
# │   ├── Dummy.hpp
# │   ├── main.cpp
# │   ├── obj/
# │   │   ├── Warlock.o
# │   │   ├── ASpell.o
# │   │   ├── ATarget.o
# │   │   ├── Fwoosh.o
# │   │   ├── Dummy.o
# │   │   ├── main.o
# ├── 02/
# │   ├── _subject.txt
# │   ├── Warlock.cpp
# │   ├── Warlock.hpp
# │   ├── ASpell.cpp
# │   ├── ASpell.hpp
# │   ├── ATarget.cpp
# │   ├── ATarget.hpp
# │   ├── Fwoosh.cpp
# │   ├── Fwoosh.hpp
# │   ├── Dummy.cpp
# │   ├── Dummy.hpp
# │   ├── Fireball.cpp
# │   ├── Fireball.hpp
# │   ├── Polymorph.cpp
# │   ├── Polymorph.hpp
# │   ├── BrickWall.cpp
# │   ├── BrickWall.hpp
# │   ├── SpellBook.cpp
# │   ├── SpellBook.hpp
# │   ├── TargetGenerator.cpp
# │   ├── TargetGenerator.hpp
# │   ├── main.cpp
# │   ├── obj/
# │   │   ├── Warlock.o
# │   │   ├── ASpell.o
# │   │   ├── ATarget.o
# │   │   ├── Fwoosh.o
# │   │   ├── Dummy.o
# │   │   ├── Fireball.o
# │   │   ├── Polymorph.o
# │   │   ├── BrickWall.o
# │   │   ├── SpellBook.o
# │   │   ├── TargetGenerator.o
# │   │   ├── main.o
# ├── Makefile
# ├── module00
# ├── module01
# ├── module02
