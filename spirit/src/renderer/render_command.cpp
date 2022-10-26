#include "renderer/render_command.hpp"

namespace Spirit {
	Scope<RenderAPI> RenderCommand::s_RenderAPI = RenderAPI::Create();
}
