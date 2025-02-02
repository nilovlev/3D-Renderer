#include "application.h"
#include "except.h"

int main() {
  try {
    renderer::Application application;
    application.run();
  } catch (...) {
    except::react();
  }
  return 0;
}
