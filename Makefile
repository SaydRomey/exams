
.PHONY: all exam

# all:
# 	@echo "'make exam' -> launch JCluzet's GRADEME"

exam:
	@bash -c "$$(curl https://grademe.fr)"
