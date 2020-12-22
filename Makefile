all: configure build

BUILD_DIR=build
BUILD_GENERATOR=Ninja
CONFIGURE_OPTS=-G$(BUILD_GENERATOR)

.PHONY: realclean
realclean:
	rm -rf $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: configure
configure:
	cmake -S . -B $(BUILD_DIR) $(CONFIGURE_OPTS)

.PHONY: build
build:
	cmake --build $(BUILD_DIR) -j$(nproc)


.PHONY: build-and-test
build-and-test:
	ctest --build-and-test . $(BUILD_DIR) --build-generator $(BUILD_GENERATOR)

.PHONY: test
test:
	(cd $(BUILD_DIR) && ctest)
