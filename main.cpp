#include "absl/log/initialize.h"
#include "app/app.h"

int main() {
    absl::InitializeLog();

    App app;

    app.Run();

    return 0;
}
