all: configure build

BUILD_DIR=build
CONFIGURE_OPTS=-DCATCH_INSTALL_EXTRAS=OFF -DCATCH_INSTALL_DOCS=OFF -DCATCH_BUILD_TESTING=OFF

.PHONY: configure
configure:
	cmake -S . -B $(BUILD_DIR) $(CONFIGURE_OPTS)

.PHONY: build
build:
	cmake --build $(BUILD_DIR) -j$(nproc)
