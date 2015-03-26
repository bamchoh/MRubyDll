// ConsoleApplication12.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
#include "MRubyDll.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace MRuby {
	MRuby::MRuby() {
		mrb = mrb_open();
		cxt = mrbc_context_new(mrb);
	}

	MRuby::~MRuby() {
		mrbc_context_free(mrb, cxt);
	}

	Int32 MRuby::Load(System::String ^ code_string) {
		mrb_value v;

		IntPtr mrb_text = Marshal::StringToHGlobalAnsi(code_string);

		v = mrb_load_string_cxt(mrb, (const char*)mrb_text.ToPointer(), cxt);

		if (mrb->exc) {
			if (!mrb_undef_p(v)) {
				mrb_print_error(mrb);
			}
			return -1;
		}

		return 0;
	}
}

