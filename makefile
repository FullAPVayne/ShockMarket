OBJECTS = Main.o Market.o imgui/imgui.o imgui/imgui_draw.o imgui/imgui_tables.o imgui/imgui_widgets.o imgui/backends/imgui_impl_glfw.o imgui/backends/imgui_impl_opengl2.o

CXXFLAGS += `pkg-config --cflags glfw3` -I imgui -I imgui/backends
LDFLAGS += -lGL `pkg-config --libs glfw3`

.PHONY: all clean

all: shock_market

shock_market: $(OBJECTS)
	@$(CXX) $(OBJECTS) $(LDFLAGS) -o $@ 

%.o: %.cpp
	@$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	@rm -f *.o shock_market