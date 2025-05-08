#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

int main() {
  using namespace ftxui;
  ScreenInteractive screen = ScreenInteractive::FitComponent();

  int selection_1 = 0;
  int selection_2 = 0;

  auto entries = std::vector<std::string>{
      "Hello, World!",
      "Hello, FTXUI!",
      "Hello, C++!",
  };

  auto radiobox_1 = Radiobox(&entries, &selection_1);
  auto radiobox_2 = Radiobox(&entries, &selection_2);

  std::string inputed_text = "";
  auto input = Input(&inputed_text, "Input text");

  auto quit_button =
      Button("Quit", screen.ExitLoopClosure(), ButtonOption::Animated());

  auto container = Container::Vertical({
      Container::Horizontal({
          radiobox_1,
          radiobox_2,
      }),
      input,
      quit_button,
  });

  // Customize the container render function.
  auto renderer = Renderer(container, [&] {

      auto styled_radiobox_1 = 
        vbox({
          text("First radiobox:"),
          radiobox_1->Render(),
          separator(),
          text("selected: " + std::to_string(selection_1)),
        });
      styled_radiobox_1 |= borderStyled(DASHED, Color::Green);

      auto styled_radiobox_2 = 
        vbox({
          text("Second radiobox:"),
          radiobox_2->Render(),
          separator(),
          text("selected: " + std::to_string(selection_2)),
        });
      styled_radiobox_2 |= borderStyled(DASHED, Color::Red);

      auto styled_input = 
        vbox({
          text("Input:"),
          input->Render(),
          separator(),
          paragraph("inputed_text: " + inputed_text),
        });
      styled_input |= borderStyled(DASHED, Color::Blue);

      auto document = vbox({
          vbox({
              hbox({
              styled_radiobox_1,
              styled_radiobox_2,
              }),
              styled_input,
              quit_button->Render(),
          })
      });

      return document;
  });

  screen.Loop(renderer);

  return 0;
}
