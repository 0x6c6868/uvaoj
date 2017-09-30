CC:=gcc
FILES=`ls *.c`

define compile_c_file
@for file in $(FILES); do \
( echo "$(CC) -o $${file%.c*} $$file" && $(CC) -o $${file%.c*} $$file ) \
done;
endef

all:
	$(call compile_c_file)
