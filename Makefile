CC:=gcc
FILES=`ls *.c`

define compile_c_file
@for file in $(FILES); do \
( echo "$(CC) -o $${file%.c*} $$file" && $(CC) -o $${file%.c*} $$file ) \
done;
endef

all:
	$(call compile_c_file)

define format_c_file
@for file in $(FILES); do \
( echo "clang-format -i $$file" && clang-format -i $$file ) \
done;
endef

format:
	$(call format_c_file)