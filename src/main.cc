#include "app.h"
#include "imgui.h"

int main(int argc, char** argv) {

    RunSolApplication({600, 400, "essa window"}, [] () {
        bool show_demo = true;
        ImGui::ShowDemoWindow(&show_demo);
    });

    return 0;
}