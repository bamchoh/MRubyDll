#include <Windows.h>
#include "mruby.h"
#include "mruby/array.h"
#include "mruby/compile.h"
#include "mruby/dump.h"
#include "mruby/variable.h"

namespace MRuby {
	public ref class MRuby
	{
	private:
		mrb_state* mrb;
		mrbc_context *cxt;

	public:
		MRuby();

		~MRuby();

		int Load(System::String ^ code_string);
	};
}

