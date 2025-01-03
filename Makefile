
# 👤 Project Info
AUTHOR		:= cdumais
REPO_LINK	:= https://github.com/SaydRomey/exams

# ⚙️ Default 'make' target
.DEFAULT_GOAL	:= all

# 📜 Handle invalid targets
.DEFAULT:
	$(info make: *** No rule to make target '$(MAKECMDGOALS)'.  Stop.)
	@$(MAKE) help --no-print-directory

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

# 🎯 Output Macros
INFO		= echo "[$(BOLD)$(PURPLE)$(1)$(RESET)]\t$(ORANGE)$(2)$(RESET)$(GRAYTALIC)$(3)$(RESET)"
SUCCESS		= echo "[$(BOLD)$(PURPLE)$(1)$(RESET)]\t$(GREEN)$(2)$(RESET)"
WARNING		= echo "[$(BOLD)$(PURPLE)$(1)$(RESET)]\t$(YELLOW)$(2)$(RESET)"
ERROR		= echo "❌ Error: $(1) $(RED)$(2)$(RESET)"

# 🛠️ Build Configuration
C_FLAGS	:= -Wall -Wextra -Werror
COMPILE	:= gcc $(C_FLAGS)

# 🛠️ Utility Commands
REMOVE	:= rm -rf
MKDIR	:= mkdir -p

# 📂 Directories
RANK2	:= rank2
RANK3	:= rank3
RANK4	:= rank4
RANK5	:= rank5

# 📄 Specific Files
QUESTION_RANDOMIZER_SRC	:= $(RANK2)/question_randomizer.c
QUESTION_RANDOMIZER_BIN	:= question_randomizer
GRADEME_FILE			:= 42-EXAM

# 📑 Subjects
FT_PRINTF_SUBJECT		:= $(RANK3)/ft_printf/_subject.txt
GET_NEXT_LINE_SUBJECT	:= $(RANK3)/get_next_line/_subject.txt
MICROSHELL_SUBJECT		:= $(RANK4)/_subject.txt

# 📖 Notes
NOTES_R2	:= $(RANK2)/notes.txt
NOTES_R4	:= $(RANK4)/notes.txt

# ==============================
##@ 🚀 General
# ==============================
all: ## Main menu for project actions
	@echo "$(BOLD)Choose an action:$(RESET)"
	@echo "0) Launch JCluzet's GRADEME"
	@echo "1) Execute question randomizer (rank 2)"
	@echo "2) Open GitHub repository"
	@echo "3) Show all 'make' options"
	@read -p "Enter your choice: " choice; \
	case $$choice in \
		0) $(MAKE) exam ;; \
		1) $(MAKE) rand_question ;; \
		2) $(MAKE) repo ;; \
		3) $(MAKE) help ;; \
		*) $(call ERROR,Invalid choice:,$$choice) ;; \
	esac

# 📝 Exam Simulator
exam: ## Launch JCluzet's GRADEME
	@read -p "Are you sure you want to launch GRADEME? (y/n): " confirm; \
	if [ "$$confirm" = "y" ]; then \
		bash -c "$$(curl https://grademe.fr)"; \
	else \
		$(call WARNING,Action cancelled:,GRADEME was not launched); \
	fi

# 🎲 Randomized rank2 question
rand_question: ## Run question randomizer (Rank 2)
	@$(call INFO,question_randomizer,Compiling...)
	@$(COMPILE) $(QUESTION_RANDOMIZER_SRC) -o $(QUESTION_RANDOMIZER_BIN)
	@$(call SUCCESS,question_randomizer,Compilation successful!)
	@$(call INFO,question_randomizer,Executing randomizer...)
	@./$(QUESTION_RANDOMIZER_BIN)

# 🔗 GitHub Repository
repo: ## Open the GitHub repository
	@echo "Opening $(AUTHOR)'s GitHub repository..."
	@open $(REPO_LINK)

# ==============================
##@ 📚 Documentation
# ==============================
subjects: ## Show subject for a specific rank
	@echo "$(BOLD)Choose a rank to view subjects:$(RESET)"
	@echo "2) rank2 | 3) rank3 | 4) rank4 | 5) rank5"
	@read -p "Enter your choice: " rank; \
	case $$rank in \
		2) $(call WARNING,rank2,No subjects are available in this rank.) ;; \
		3) \
			echo "$(BOLD)Choose a subject in rank3:$(RESET)"; \
			echo "1) ft_printf | 2) get_next_line"; \
			read -p "Enter your choice: " subject; \
			case $$subject in \
				1) [ -f $(FT_PRINTF_SUBJECT) ] && cat $(FT_PRINTF_SUBJECT) || $(call ERROR,Subject not found:, $(FT_PRINTF_SUBJECT)) ;; \
				2) [ -f $(GET_NEXT_LINE_SUBJECT) ] && cat $(GET_NEXT_LINE_SUBJECT) || $(call ERROR,Subject not found:, $(GET_NEXT_LINE_SUBJECT)) ;; \
				*) $(call ERROR,Invalid choice:,$$subject) ;; \
			esac ;; \
		4) [ -f $(MICROSHELL_SUBJECT) ] && cat $(MICROSHELL_SUBJECT) || $(call ERROR,Subject not found:, $(MICROSHELL_SUBJECT)) ;; \
		5) \
			echo "$(BOLD)Switching to rank5...$(RESET)"; \
			$(MAKE) -C $(RANK5) subject ;; \
		*) $(call ERROR,Invalid rank choice:,$$rank) ;; \
	esac

notes: ## View notes for a specific rank
	@echo "$(BOLD)Choose a rank to view notes:$(RESET)"
	@echo "2) rank2 | 4) rank4"
	@read -p "Enter your choice: " rank; \
	case $$rank in \
		2) [ -f $(NOTES_R2) ] && cat $(NOTES_R2) | more || $(call ERROR,Notes not found:, $(NOTES_R2)) ;; \
		4) [ -f $(NOTES_R4) ] && cat $(NOTES_R4) | more || $(call ERROR,Notes not found:, $(NOTES_R4)) ;; \
		*) $(call ERROR,Invalid rank choice:,$$rank) ;; \
	esac

# ==============================
##@ 🧹 Cleanup
# ==============================
clean: ## Remove object files (none currently handled by this)
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(REMOVE) $(OBJ_DIR); \
		$(call SUCCESS,*EXAMS*,Object files removed); \
	else \
		$(call WARNING,*EXAMS*,No object files to remove); \
	fi

fclean: clean ## Remove executables and temporary files
	@if [ -f "$(QUESTION_RANDOMIZER_BIN)" ]; then \
		$(REMOVE) $(QUESTION_RANDOMIZER_BIN); \
		$(call SUCCESS,*EXAMS*,$(QUESTION_RANDOMIZER_BIN) removed); \
	else \
		$(call WARNING,*EXAMS*,No $(QUESTION_RANDOMIZER_BIN) to remove); \
	fi; \
	if [ -d "$(GRADEME_FILE)" ]; then \
		$(REMOVE) "$(GRADEME_FILE)"; \
		$(call SUCCESS,*EXAMS*,$(GRADEME_FILE) removed); \
	else \
		$(call WARNING,*EXAMS*,No $(GRADEME_FILE) to remove); \
	fi; \

ffclean: fclean ## Super clean (grademe and rank 5)
	@$(call INFO,ffclean,Performing an ultra-clean...)
	@$(MAKE) fclean -C $(RANK5)

# ==============================
##@ 🛠️  Utility
# ==============================
help: ## Display available targets
	@echo "\nAvailable targets:"
	@awk 'BEGIN {FS = ":.*##";} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "  $(CYAN)%-15s$(RESET) %s\n", $$1, $$2 \
		} \
		/^##@/ { \
			printf "\n$(BOLD)%s$(RESET)\n", substr($$0, 5) \
		}' $(MAKEFILE_LIST)


# 🔖 .Define .PHONY Targets
.PHONY: all exam rand_question repo
.PHONY: subjects notes clean fclean ffclean help

# **************************************************************************** #
# 📦 Project Root (exams)
# ├── rank2/
# │   ├── lvl1/
# │   │   ├── first_word.c
# │   │   ├── [...]
# │   ├── lvl2/
# │   │   ├── alpha_mirror.c
# │   │   ├── [...]
# │   ├── lvl3/
# │   │   ├── add_prime_sum.c
# │   │   ├── [...]
# │   ├── lvl4/
# │   │   ├── flood_fill.c
# │   │   ├── [...]
# │   ├── notes.txt (should have a command to cat | more)
# │   ├── question_randomizer.c (has a main, should be a target) -> (currently only prints a random question after selecting the level, will eventually print the question subject as well..)
# ├── rank3/
# │   │   ├── ft_printf/
# │   │   │   ├── _subject.txt (should have a simple 'cat' target)
# │   │   │   ├── ft_printf_exam.c
# │   │   │   ├── [...](currently no ft_printf tester, todo later...)
# │   │   ├── get_next_line/
# │   │   │   ├── _subject.txt (should have a simple 'cat' target)
# │   │   │   ├── get_next_line_exam.c
# │   │   │   ├── [...](currently no get_next_line tester, todo later...)
# ├── rank4/
# │   │   ├── _subject.txt (should have a simple 'cat' target)
# │   │   ├── microshell.c
# │   │   ├── notes.txt (should have a command to cat | more)
# ├── rank5/
# │   ├── 00/
# │   ├── 01/
# │   ├── 02/
# │   ├── Makefile (handles the rank5 folder and modules)
# ├── .gitignore
# ├── Makefile (this Makefile)
