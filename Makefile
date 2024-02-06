
.PHONY: all exam

# all:
# 	@echo "'make exam' -> launch JCluzet's GRADEME"

# add a read confirm to launch GRADEME..

exam:
	@bash -c "$$(curl https://grademe.fr)"

clean fclean ffclean:
	@rm -rf 42-EXAM

