#include "main.h"

namespace main {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2022 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Data m_sampler_11;
	Data m_sampler_7;
	Data m_sampler_9;
	Data m_sampler_15;
	Data m_sampler_3;
	Data m_sampler_5;
	Data m_sampler_13;
	Data m_sampler_1;
	Delta __m_delta_101;
	Delta __m_delta_109;
	Delta __m_delta_107;
	Delta __m_delta_79;
	Delta __m_delta_103;
	Delta __m_delta_67;
	Delta __m_delta_65;
	Delta __m_delta_105;
	Delta __m_delta_86;
	Delta __m_delta_69;
	Delta __m_delta_92;
	Delta __m_delta_84;
	Delta __m_delta_90;
	Delta __m_delta_99;
	Delta __m_delta_57;
	Delta __m_delta_96;
	Delta __m_delta_94;
	Delta __m_delta_82;
	Delta __m_delta_111;
	Delta __m_delta_113;
	Delta __m_delta_88;
	Delta __m_delta_251;
	Delta __m_delta_224;
	Delta __m_delta_197;
	Delta __m_delta_77;
	Delta __m_delta_305;
	Delta __m_delta_278;
	Delta __m_delta_170;
	Delta __m_delta_75;
	Delta __m_delta_116;
	Delta __m_delta_73;
	Delta __m_delta_71;
	Delta __m_delta_143;
	Sah __m_sah_78;
	Sah __m_sah_85;
	Sah __m_sah_68;
	Sah __m_sah_74;
	Sah __m_sah_306;
	Sah __m_sah_76;
	Sah __m_sah_83;
	Sah __m_sah_66;
	Sah __m_sah_70;
	Sah __m_sah_72;
	Sah __m_sah_102;
	Sah __m_sah_89;
	Sah __m_sah_171;
	Sah __m_sah_144;
	Sah __m_sah_117;
	Sah __m_sah_114;
	Sah __m_sah_198;
	Sah __m_sah_252;
	Sah __m_sah_225;
	Sah __m_sah_279;
	Sah __m_sah_87;
	Sah __m_sah_112;
	Sah __m_sah_108;
	Sah __m_sah_95;
	Sah __m_sah_93;
	Sah __m_sah_91;
	Sah __m_sah_110;
	Sah __m_sah_97;
	Sah __m_sah_104;
	Sah __m_sah_100;
	Sah __m_sah_106;
	Sah __m_sah_80;
	int __exception;
	int vectorsize;
	t_sample __m_count_146;
	t_sample __m_count_60;
	t_sample m_history_18;
	t_sample m_history_17;
	t_sample m_history_16;
	t_sample m_history_19;
	t_sample __m_count_119;
	t_sample m_history_20;
	t_sample m_history_23;
	t_sample __m_count_173;
	t_sample m_history_22;
	t_sample m_history_21;
	t_sample m_history_24;
	t_sample m_history_14;
	t_sample __m_count_200;
	t_sample m_history_2;
	t_sample __m_count_254;
	t_sample samplerate;
	t_sample __m_count_281;
	t_sample m_history_12;
	t_sample m_history_4;
	t_sample __m_count_227;
	t_sample m_history_6;
	t_sample m_history_10;
	t_sample m_history_8;
	t_sample __m_carry_62;
	t_sample m_history_25;
	t_sample m_history_27;
	t_sample m_trigger_44;
	t_sample m_wetdry_45;
	t_sample m_record_43;
	t_sample m_startpoint_42;
	t_sample m_playbackspeed_41;
	t_sample m_next_46;
	t_sample m_initialise_48;
	t_sample __m_carry_52;
	t_sample m_gain_47;
	t_sample __m_count_50;
	t_sample m_endpoint_49;
	t_sample m_history_26;
	t_sample m_history_40;
	t_sample m_history_38;
	t_sample m_history_30;
	t_sample m_history_31;
	t_sample m_history_29;
	t_sample m_history_28;
	t_sample m_history_39;
	t_sample m_history_32;
	t_sample m_history_34;
	t_sample m_history_37;
	t_sample m_history_33;
	t_sample m_history_36;
	t_sample m_history_35;
	t_sample __m_count_308;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_sampler_1.reset("sampler8", ((int)480000), ((int)2));
		m_history_2 = ((int)0);
		m_sampler_3.reset("sampler7", ((int)480000), ((int)2));
		m_history_4 = ((int)0);
		m_sampler_5.reset("sampler6", ((int)480000), ((int)2));
		m_history_6 = ((int)0);
		m_sampler_7.reset("sampler5", ((int)480000), ((int)2));
		m_history_8 = ((int)0);
		m_sampler_9.reset("sampler4", ((int)480000), ((int)2));
		m_history_10 = ((int)0);
		m_sampler_11.reset("sampler3", ((int)480000), ((int)2));
		m_history_12 = ((int)0);
		m_sampler_13.reset("sampler2", ((int)480000), ((int)2));
		m_history_14 = ((int)0);
		m_sampler_15.reset("sampler1", ((int)480000), ((int)2));
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_history_24 = ((int)0);
		m_history_25 = ((int)0);
		m_history_26 = ((int)0);
		m_history_27 = ((int)0);
		m_history_28 = ((int)0);
		m_history_29 = ((int)0);
		m_history_30 = ((int)0);
		m_history_31 = ((int)0);
		m_history_32 = ((int)0);
		m_history_33 = ((int)0);
		m_history_34 = ((int)0);
		m_history_35 = ((int)0);
		m_history_36 = ((int)0);
		m_history_37 = ((int)0);
		m_history_38 = ((int)0);
		m_history_39 = ((int)0);
		m_history_40 = ((int)0);
		m_playbackspeed_41 = ((int)0);
		m_startpoint_42 = ((int)0);
		m_record_43 = ((int)0);
		m_trigger_44 = ((int)0);
		m_wetdry_45 = ((int)0);
		m_next_46 = ((int)0);
		m_gain_47 = ((int)0);
		m_initialise_48 = ((int)0);
		m_endpoint_49 = ((int)0);
		__m_count_50 = 0;
		__m_carry_52 = 0;
		__m_delta_57.reset(0);
		__m_count_60 = 0;
		__m_carry_62 = 0;
		__m_delta_65.reset(0);
		__m_sah_66.reset(0);
		__m_delta_67.reset(0);
		__m_sah_68.reset(0);
		__m_delta_69.reset(0);
		__m_sah_70.reset(0);
		__m_delta_71.reset(0);
		__m_sah_72.reset(0);
		__m_delta_73.reset(0);
		__m_sah_74.reset(0);
		__m_delta_75.reset(0);
		__m_sah_76.reset(0);
		__m_delta_77.reset(0);
		__m_sah_78.reset(0);
		__m_delta_79.reset(0);
		__m_sah_80.reset(0);
		__m_delta_82.reset(0);
		__m_sah_83.reset(0);
		__m_delta_84.reset(0);
		__m_sah_85.reset(0);
		__m_delta_86.reset(0);
		__m_sah_87.reset(0);
		__m_delta_88.reset(0);
		__m_sah_89.reset(0);
		__m_delta_90.reset(0);
		__m_sah_91.reset(0);
		__m_delta_92.reset(0);
		__m_sah_93.reset(0);
		__m_delta_94.reset(0);
		__m_sah_95.reset(0);
		__m_delta_96.reset(0);
		__m_sah_97.reset(0);
		__m_delta_99.reset(0);
		__m_sah_100.reset(0);
		__m_delta_101.reset(0);
		__m_sah_102.reset(0);
		__m_delta_103.reset(0);
		__m_sah_104.reset(0);
		__m_delta_105.reset(0);
		__m_sah_106.reset(0);
		__m_delta_107.reset(0);
		__m_sah_108.reset(0);
		__m_delta_109.reset(0);
		__m_sah_110.reset(0);
		__m_delta_111.reset(0);
		__m_sah_112.reset(0);
		__m_delta_113.reset(0);
		__m_sah_114.reset(0);
		__m_delta_116.reset(0);
		__m_sah_117.reset(0);
		__m_count_119 = 0;
		__m_delta_143.reset(0);
		__m_sah_144.reset(0);
		__m_count_146 = 0;
		__m_delta_170.reset(0);
		__m_sah_171.reset(0);
		__m_count_173 = 0;
		__m_delta_197.reset(0);
		__m_sah_198.reset(0);
		__m_count_200 = 0;
		__m_delta_224.reset(0);
		__m_sah_225.reset(0);
		__m_count_227 = 0;
		__m_delta_251.reset(0);
		__m_sah_252.reset(0);
		__m_count_254 = 0;
		__m_delta_278.reset(0);
		__m_sah_279.reset(0);
		__m_count_281 = 0;
		__m_delta_305.reset(0);
		__m_sah_306.reset(0);
		__m_count_308 = 0;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int switch_678 = (m_next_46 ? ((int)1) : ((int)0));
		int switch_375 = (m_initialise_48 ? ((int)1) : ((int)0));
		int iffalse_118 = (-1);
		int sampler1_dim = m_sampler_15.dim;
		int sampler1_channels = m_sampler_15.channels;
		bool chan_ignore_121 = ((((int)1) < 0) || (((int)1) >= sampler1_channels));
		int chan_wrap_129 = wrap(1, 0, sampler1_channels);
		int min_133 = (-1);
		int min_142 = (-1);
		int iffalse_145 = (-1);
		int sampler2_dim = m_sampler_13.dim;
		int sampler2_channels = m_sampler_13.channels;
		bool chan_ignore_148 = ((((int)1) < 0) || (((int)1) >= sampler2_channels));
		int chan_wrap_156 = wrap(1, 0, sampler2_channels);
		int min_160 = (-1);
		int min_169 = (-1);
		int iffalse_172 = (-1);
		int sampler3_dim = m_sampler_11.dim;
		int sampler3_channels = m_sampler_11.channels;
		bool chan_ignore_175 = ((((int)1) < 0) || (((int)1) >= sampler3_channels));
		int chan_wrap_183 = wrap(1, 0, sampler3_channels);
		int min_187 = (-1);
		int min_196 = (-1);
		int iffalse_199 = (-1);
		int sampler4_dim = m_sampler_9.dim;
		int sampler4_channels = m_sampler_9.channels;
		bool chan_ignore_202 = ((((int)1) < 0) || (((int)1) >= sampler4_channels));
		int min_213 = (-1);
		int chan_wrap_219 = wrap(1, 0, sampler4_channels);
		int min_223 = (-1);
		int iffalse_226 = (-1);
		int sampler5_dim = m_sampler_7.dim;
		int sampler5_channels = m_sampler_7.channels;
		bool chan_ignore_230 = ((((int)1) < 0) || (((int)1) >= sampler5_channels));
		int min_240 = (-1);
		int chan_wrap_246 = wrap(1, 0, sampler5_channels);
		int min_250 = (-1);
		int iffalse_253 = (-1);
		int sampler6_dim = m_sampler_5.dim;
		int sampler6_channels = m_sampler_5.channels;
		bool chan_ignore_257 = ((((int)1) < 0) || (((int)1) >= sampler6_channels));
		int chan_wrap_264 = wrap(1, 0, sampler6_channels);
		int min_268 = (-1);
		int min_277 = (-1);
		int iffalse_280 = (-1);
		int sampler7_dim = m_sampler_3.dim;
		int sampler7_channels = m_sampler_3.channels;
		bool chan_ignore_284 = ((((int)1) < 0) || (((int)1) >= sampler7_channels));
		int chan_wrap_291 = wrap(1, 0, sampler7_channels);
		int min_295 = (-1);
		int min_304 = (-1);
		int iffalse_307 = (-1);
		int sampler8_dim = m_sampler_1.dim;
		int sampler8_channels = m_sampler_1.channels;
		bool chan_ignore_311 = ((((int)1) < 0) || (((int)1) >= sampler8_channels));
		int chan_wrap_318 = wrap(1, 0, sampler8_channels);
		int min_322 = (-1);
		int min_331 = (-1);
		int min_332 = (-1);
		int min_333 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out3 = m_trigger_44;
			__m_count_50 = (((int)0) ? 0 : (fixdenorm(__m_count_50 + switch_678)));
			int carry_51 = 0;
			if ((((int)0) != 0)) {
				__m_count_50 = 0;
				__m_carry_52 = 0;
				
			} else if (((((int)9) > 0) && (__m_count_50 >= ((int)9)))) {
				int wraps_53 = (__m_count_50 / ((int)9));
				__m_carry_52 = (__m_carry_52 + wraps_53);
				__m_count_50 = (__m_count_50 - (wraps_53 * ((int)9)));
				carry_51 = 1;
				
			};
			int counter_672 = __m_count_50;
			int counter_673 = carry_51;
			int counter_674 = __m_carry_52;
			int sub_23074 = (counter_672 - ((int)0));
			t_sample scale_23071 = ((safepow((sub_23074 * ((t_sample)0.125)), ((int)1)) * ((int)8)) + ((int)0));
			t_sample choice_54 = int(scale_23071);
			t_sample gate_765 = (((choice_54 >= 1) && (choice_54 < 2)) ? in1 : 0);
			t_sample gate_766 = (((choice_54 >= 2) && (choice_54 < 3)) ? in1 : 0);
			t_sample gate_767 = (((choice_54 >= 3) && (choice_54 < 4)) ? in1 : 0);
			t_sample gate_768 = (((choice_54 >= 4) && (choice_54 < 5)) ? in1 : 0);
			t_sample gate_769 = (((choice_54 >= 5) && (choice_54 < 6)) ? in1 : 0);
			t_sample gate_770 = (((choice_54 >= 6) && (choice_54 < 7)) ? in1 : 0);
			t_sample gate_771 = (((choice_54 >= 7) && (choice_54 < 8)) ? in1 : 0);
			t_sample gate_772 = ((choice_54 >= 8) ? in1 : 0);
			t_sample choice_55 = int(scale_23071);
			t_sample gate_757 = (((choice_55 >= 1) && (choice_55 < 2)) ? in2 : 0);
			t_sample gate_758 = (((choice_55 >= 2) && (choice_55 < 3)) ? in2 : 0);
			t_sample gate_759 = (((choice_55 >= 3) && (choice_55 < 4)) ? in2 : 0);
			t_sample gate_760 = (((choice_55 >= 4) && (choice_55 < 5)) ? in2 : 0);
			t_sample gate_761 = (((choice_55 >= 5) && (choice_55 < 6)) ? in2 : 0);
			t_sample gate_762 = (((choice_55 >= 6) && (choice_55 < 7)) ? in2 : 0);
			t_sample gate_763 = (((choice_55 >= 7) && (choice_55 < 8)) ? in2 : 0);
			t_sample gate_764 = ((choice_55 >= 8) ? in2 : 0);
			t_sample choice_56 = int(scale_23071);
			t_sample gate_664 = (((choice_56 >= 1) && (choice_56 < 2)) ? m_record_43 : 0);
			t_sample gate_665 = (((choice_56 >= 2) && (choice_56 < 3)) ? m_record_43 : 0);
			t_sample gate_666 = (((choice_56 >= 3) && (choice_56 < 4)) ? m_record_43 : 0);
			t_sample gate_667 = (((choice_56 >= 4) && (choice_56 < 5)) ? m_record_43 : 0);
			t_sample gate_668 = (((choice_56 >= 5) && (choice_56 < 6)) ? m_record_43 : 0);
			t_sample gate_669 = (((choice_56 >= 6) && (choice_56 < 7)) ? m_record_43 : 0);
			t_sample gate_670 = (((choice_56 >= 7) && (choice_56 < 8)) ? m_record_43 : 0);
			t_sample gate_671 = ((choice_56 >= 8) ? m_record_43 : 0);
			int delta_635 = __m_delta_57(counter_672);
			t_sample choice_58 = int(scale_23071);
			t_sample input_59 = (m_trigger_44 + delta_635);
			t_sample gate_749 = (((choice_58 >= 1) && (choice_58 < 2)) ? input_59 : 0);
			t_sample gate_750 = (((choice_58 >= 2) && (choice_58 < 3)) ? input_59 : 0);
			t_sample gate_751 = (((choice_58 >= 3) && (choice_58 < 4)) ? input_59 : 0);
			t_sample gate_752 = (((choice_58 >= 4) && (choice_58 < 5)) ? input_59 : 0);
			t_sample gate_753 = (((choice_58 >= 5) && (choice_58 < 6)) ? input_59 : 0);
			t_sample gate_754 = (((choice_58 >= 6) && (choice_58 < 7)) ? input_59 : 0);
			t_sample gate_755 = (((choice_58 >= 7) && (choice_58 < 8)) ? input_59 : 0);
			t_sample gate_756 = ((choice_58 >= 8) ? input_59 : 0);
			__m_count_60 = (((int)0) ? 0 : (fixdenorm(__m_count_60 + (switch_375 + switch_678))));
			int carry_61 = 0;
			if ((((int)0) != 0)) {
				__m_count_60 = 0;
				__m_carry_62 = 0;
				
			} else if (((((int)9) > 0) && (__m_count_60 >= ((int)9)))) {
				int wraps_63 = (__m_count_60 / ((int)9));
				__m_carry_62 = (__m_carry_62 + wraps_63);
				__m_count_60 = (__m_count_60 - (wraps_63 * ((int)9)));
				carry_61 = 1;
				
			};
			int counter_377 = __m_count_60;
			int counter_378 = carry_61;
			int counter_379 = __m_carry_62;
			int choice_64 = counter_377;
			t_sample gate_707 = (((choice_64 >= 1) && (choice_64 < 2)) ? m_startpoint_42 : 0);
			t_sample gate_708 = (((choice_64 >= 2) && (choice_64 < 3)) ? m_startpoint_42 : 0);
			t_sample gate_709 = (((choice_64 >= 3) && (choice_64 < 4)) ? m_startpoint_42 : 0);
			t_sample gate_710 = (((choice_64 >= 4) && (choice_64 < 5)) ? m_startpoint_42 : 0);
			t_sample gate_711 = (((choice_64 >= 5) && (choice_64 < 6)) ? m_startpoint_42 : 0);
			t_sample gate_712 = (((choice_64 >= 6) && (choice_64 < 7)) ? m_startpoint_42 : 0);
			t_sample gate_713 = (((choice_64 >= 7) && (choice_64 < 8)) ? m_startpoint_42 : 0);
			t_sample gate_714 = ((choice_64 >= 8) ? m_startpoint_42 : 0);
			int expr_632 = ((int)0);
			int expr_631 = ((int)0);
			if ((gate_707 == ((int)0))) {
				expr_631 = ((int)1);
				
			} else {
				expr_631 = ((int)0);
				
			};
			if ((gate_707 == ((int)0))) {
				expr_632 = ((int)1);
				
			} else {
				expr_632 = ((int)0);
				
			};
			t_sample switch_628 = (expr_632 ? m_history_40 : ((int)0));
			t_sample delta_626 = __m_delta_65(switch_628);
			t_sample sah_625 = __m_sah_66(switch_628, delta_626, ((int)0));
			t_sample switch_624 = (expr_631 ? sah_625 : gate_707);
			t_sample history_630_next_633 = fixdenorm(gate_707);
			int expr_357 = ((int)0);
			int expr_358 = ((int)0);
			if ((gate_708 == ((int)0))) {
				expr_358 = ((int)1);
				
			} else {
				expr_358 = ((int)0);
				
			};
			if ((gate_708 == ((int)0))) {
				expr_357 = ((int)1);
				
			} else {
				expr_357 = ((int)0);
				
			};
			t_sample switch_354 = (expr_358 ? m_history_39 : ((int)0));
			t_sample delta_352 = __m_delta_67(switch_354);
			t_sample sah_351 = __m_sah_68(switch_354, delta_352, ((int)0));
			t_sample switch_350 = (expr_357 ? sah_351 : gate_708);
			t_sample history_356_next_359 = fixdenorm(gate_708);
			int expr_345 = ((int)0);
			int expr_346 = ((int)0);
			if ((gate_709 == ((int)0))) {
				expr_346 = ((int)1);
				
			} else {
				expr_346 = ((int)0);
				
			};
			if ((gate_709 == ((int)0))) {
				expr_345 = ((int)1);
				
			} else {
				expr_345 = ((int)0);
				
			};
			t_sample switch_342 = (expr_346 ? m_history_38 : ((int)0));
			t_sample delta_340 = __m_delta_69(switch_342);
			t_sample sah_339 = __m_sah_70(switch_342, delta_340, ((int)0));
			t_sample switch_338 = (expr_345 ? sah_339 : gate_709);
			t_sample history_344_next_347 = fixdenorm(gate_709);
			int expr_334 = ((int)0);
			int expr_333 = ((int)0);
			if ((gate_710 == ((int)0))) {
				expr_333 = ((int)1);
				
			} else {
				expr_333 = ((int)0);
				
			};
			if ((gate_710 == ((int)0))) {
				expr_334 = ((int)1);
				
			} else {
				expr_334 = ((int)0);
				
			};
			t_sample switch_330 = (expr_334 ? m_history_37 : ((int)0));
			t_sample delta_328 = __m_delta_71(switch_330);
			t_sample sah_327 = __m_sah_72(switch_330, delta_328, ((int)0));
			t_sample switch_326 = (expr_333 ? sah_327 : gate_710);
			t_sample history_332_next_335 = fixdenorm(gate_710);
			int expr_322 = ((int)0);
			int expr_321 = ((int)0);
			if ((gate_711 == ((int)0))) {
				expr_321 = ((int)1);
				
			} else {
				expr_321 = ((int)0);
				
			};
			if ((gate_711 == ((int)0))) {
				expr_322 = ((int)1);
				
			} else {
				expr_322 = ((int)0);
				
			};
			t_sample switch_318 = (expr_322 ? m_history_36 : ((int)0));
			t_sample delta_316 = __m_delta_73(switch_318);
			t_sample sah_315 = __m_sah_74(switch_318, delta_316, ((int)0));
			t_sample switch_314 = (expr_321 ? sah_315 : gate_711);
			t_sample history_320_next_323 = fixdenorm(gate_711);
			int expr_309 = ((int)0);
			int expr_310 = ((int)0);
			if ((gate_712 == ((int)0))) {
				expr_310 = ((int)1);
				
			} else {
				expr_310 = ((int)0);
				
			};
			if ((gate_712 == ((int)0))) {
				expr_309 = ((int)1);
				
			} else {
				expr_309 = ((int)0);
				
			};
			t_sample switch_306 = (expr_310 ? m_history_35 : ((int)0));
			t_sample delta_304 = __m_delta_75(switch_306);
			t_sample sah_303 = __m_sah_76(switch_306, delta_304, ((int)0));
			t_sample switch_302 = (expr_309 ? sah_303 : gate_712);
			t_sample history_308_next_311 = fixdenorm(gate_712);
			int expr_297 = ((int)0);
			int expr_298 = ((int)0);
			if ((gate_713 == ((int)0))) {
				expr_298 = ((int)1);
				
			} else {
				expr_298 = ((int)0);
				
			};
			if ((gate_713 == ((int)0))) {
				expr_297 = ((int)1);
				
			} else {
				expr_297 = ((int)0);
				
			};
			t_sample switch_294 = (expr_298 ? m_history_34 : ((int)0));
			t_sample delta_292 = __m_delta_77(switch_294);
			t_sample sah_291 = __m_sah_78(switch_294, delta_292, ((int)0));
			t_sample switch_290 = (expr_297 ? sah_291 : gate_713);
			t_sample history_296_next_299 = fixdenorm(gate_713);
			int expr_285 = ((int)0);
			int expr_286 = ((int)0);
			if ((gate_714 == ((int)0))) {
				expr_286 = ((int)1);
				
			} else {
				expr_286 = ((int)0);
				
			};
			if ((gate_714 == ((int)0))) {
				expr_285 = ((int)1);
				
			} else {
				expr_285 = ((int)0);
				
			};
			t_sample switch_282 = (expr_286 ? m_history_33 : ((int)0));
			t_sample delta_280 = __m_delta_79(switch_282);
			t_sample sah_279 = __m_sah_80(switch_282, delta_280, ((int)0));
			t_sample switch_278 = (expr_285 ? sah_279 : gate_714);
			t_sample history_284_next_287 = fixdenorm(gate_714);
			int choice_81 = counter_377;
			t_sample gate_699 = (((choice_81 >= 1) && (choice_81 < 2)) ? m_endpoint_49 : 0);
			t_sample gate_700 = (((choice_81 >= 2) && (choice_81 < 3)) ? m_endpoint_49 : 0);
			t_sample gate_701 = (((choice_81 >= 3) && (choice_81 < 4)) ? m_endpoint_49 : 0);
			t_sample gate_702 = (((choice_81 >= 4) && (choice_81 < 5)) ? m_endpoint_49 : 0);
			t_sample gate_703 = (((choice_81 >= 5) && (choice_81 < 6)) ? m_endpoint_49 : 0);
			t_sample gate_704 = (((choice_81 >= 6) && (choice_81 < 7)) ? m_endpoint_49 : 0);
			t_sample gate_705 = (((choice_81 >= 7) && (choice_81 < 8)) ? m_endpoint_49 : 0);
			t_sample gate_706 = ((choice_81 >= 8) ? m_endpoint_49 : 0);
			int expr_369 = ((int)0);
			int expr_370 = ((int)0);
			if ((gate_699 == ((int)0))) {
				expr_370 = ((int)1);
				
			} else {
				expr_370 = ((int)0);
				
			};
			if ((gate_699 == ((int)0))) {
				expr_369 = ((int)1);
				
			} else {
				expr_369 = ((int)0);
				
			};
			t_sample switch_366 = (expr_370 ? m_history_32 : ((int)0));
			t_sample delta_364 = __m_delta_82(switch_366);
			t_sample sah_363 = __m_sah_83(switch_366, delta_364, ((int)0));
			t_sample switch_362 = (expr_369 ? sah_363 : gate_699);
			t_sample history_368_next_371 = fixdenorm(gate_699);
			int expr_274 = ((int)0);
			int expr_273 = ((int)0);
			if ((gate_700 == ((int)0))) {
				expr_273 = ((int)1);
				
			} else {
				expr_273 = ((int)0);
				
			};
			if ((gate_700 == ((int)0))) {
				expr_274 = ((int)1);
				
			} else {
				expr_274 = ((int)0);
				
			};
			t_sample switch_270 = (expr_274 ? m_history_31 : ((int)0));
			t_sample delta_268 = __m_delta_84(switch_270);
			t_sample sah_267 = __m_sah_85(switch_270, delta_268, ((int)0));
			t_sample switch_266 = (expr_273 ? sah_267 : gate_700);
			t_sample history_272_next_275 = fixdenorm(gate_700);
			int expr_261 = ((int)0);
			int expr_262 = ((int)0);
			if ((gate_701 == ((int)0))) {
				expr_262 = ((int)1);
				
			} else {
				expr_262 = ((int)0);
				
			};
			if ((gate_701 == ((int)0))) {
				expr_261 = ((int)1);
				
			} else {
				expr_261 = ((int)0);
				
			};
			t_sample switch_258 = (expr_262 ? m_history_30 : ((int)0));
			t_sample delta_256 = __m_delta_86(switch_258);
			t_sample sah_255 = __m_sah_87(switch_258, delta_256, ((int)0));
			t_sample switch_254 = (expr_261 ? sah_255 : gate_701);
			t_sample history_260_next_263 = fixdenorm(gate_701);
			int expr_249 = ((int)0);
			int expr_250 = ((int)0);
			if ((gate_702 == ((int)0))) {
				expr_250 = ((int)1);
				
			} else {
				expr_250 = ((int)0);
				
			};
			if ((gate_702 == ((int)0))) {
				expr_249 = ((int)1);
				
			} else {
				expr_249 = ((int)0);
				
			};
			t_sample switch_246 = (expr_250 ? m_history_29 : ((int)0));
			t_sample delta_244 = __m_delta_88(switch_246);
			t_sample sah_243 = __m_sah_89(switch_246, delta_244, ((int)0));
			t_sample switch_242 = (expr_249 ? sah_243 : gate_702);
			t_sample history_248_next_251 = fixdenorm(gate_702);
			int expr_238 = ((int)0);
			int expr_237 = ((int)0);
			if ((gate_703 == ((int)0))) {
				expr_237 = ((int)1);
				
			} else {
				expr_237 = ((int)0);
				
			};
			if ((gate_703 == ((int)0))) {
				expr_238 = ((int)1);
				
			} else {
				expr_238 = ((int)0);
				
			};
			t_sample switch_234 = (expr_238 ? m_history_28 : ((int)0));
			t_sample delta_232 = __m_delta_90(switch_234);
			t_sample sah_231 = __m_sah_91(switch_234, delta_232, ((int)0));
			t_sample switch_230 = (expr_237 ? sah_231 : gate_703);
			t_sample history_236_next_239 = fixdenorm(gate_703);
			int expr_225 = ((int)0);
			int expr_226 = ((int)0);
			if ((gate_704 == ((int)0))) {
				expr_226 = ((int)1);
				
			} else {
				expr_226 = ((int)0);
				
			};
			if ((gate_704 == ((int)0))) {
				expr_225 = ((int)1);
				
			} else {
				expr_225 = ((int)0);
				
			};
			t_sample switch_222 = (expr_226 ? m_history_27 : ((int)0));
			t_sample delta_220 = __m_delta_92(switch_222);
			t_sample sah_219 = __m_sah_93(switch_222, delta_220, ((int)0));
			t_sample switch_218 = (expr_225 ? sah_219 : gate_704);
			t_sample history_224_next_227 = fixdenorm(gate_704);
			int expr_213 = ((int)0);
			int expr_214 = ((int)0);
			if ((gate_705 == ((int)0))) {
				expr_214 = ((int)1);
				
			} else {
				expr_214 = ((int)0);
				
			};
			if ((gate_705 == ((int)0))) {
				expr_213 = ((int)1);
				
			} else {
				expr_213 = ((int)0);
				
			};
			t_sample switch_210 = (expr_214 ? m_history_26 : ((int)0));
			t_sample delta_208 = __m_delta_94(switch_210);
			t_sample sah_207 = __m_sah_95(switch_210, delta_208, ((int)0));
			t_sample switch_206 = (expr_213 ? sah_207 : gate_705);
			t_sample history_212_next_215 = fixdenorm(gate_705);
			int expr_201 = ((int)0);
			int expr_202 = ((int)0);
			if ((gate_706 == ((int)0))) {
				expr_202 = ((int)1);
				
			} else {
				expr_202 = ((int)0);
				
			};
			if ((gate_706 == ((int)0))) {
				expr_201 = ((int)1);
				
			} else {
				expr_201 = ((int)0);
				
			};
			t_sample switch_198 = (expr_202 ? m_history_25 : ((int)0));
			t_sample delta_196 = __m_delta_96(switch_198);
			t_sample sah_195 = __m_sah_97(switch_198, delta_196, ((int)0));
			t_sample switch_194 = (expr_201 ? sah_195 : gate_706);
			t_sample history_200_next_203 = fixdenorm(gate_706);
			int choice_98 = counter_377;
			t_sample gate_691 = (((choice_98 >= 1) && (choice_98 < 2)) ? m_gain_47 : 0);
			t_sample gate_692 = (((choice_98 >= 2) && (choice_98 < 3)) ? m_gain_47 : 0);
			t_sample gate_693 = (((choice_98 >= 3) && (choice_98 < 4)) ? m_gain_47 : 0);
			t_sample gate_694 = (((choice_98 >= 4) && (choice_98 < 5)) ? m_gain_47 : 0);
			t_sample gate_695 = (((choice_98 >= 5) && (choice_98 < 6)) ? m_gain_47 : 0);
			t_sample gate_696 = (((choice_98 >= 6) && (choice_98 < 7)) ? m_gain_47 : 0);
			t_sample gate_697 = (((choice_98 >= 7) && (choice_98 < 8)) ? m_gain_47 : 0);
			t_sample gate_698 = ((choice_98 >= 8) ? m_gain_47 : 0);
			int expr_189 = ((int)0);
			int expr_190 = ((int)0);
			if ((gate_691 == ((int)0))) {
				expr_190 = ((int)1);
				
			} else {
				expr_190 = ((int)0);
				
			};
			if ((gate_691 == ((int)0))) {
				expr_189 = ((int)1);
				
			} else {
				expr_189 = ((int)0);
				
			};
			t_sample switch_186 = (expr_190 ? m_history_24 : ((int)0));
			t_sample delta_184 = __m_delta_99(switch_186);
			t_sample sah_183 = __m_sah_100(switch_186, delta_184, ((int)0));
			t_sample switch_182 = (expr_189 ? sah_183 : gate_691);
			t_sample history_188_next_191 = fixdenorm(gate_691);
			int expr_177 = ((int)0);
			int expr_178 = ((int)0);
			if ((gate_692 == ((int)0))) {
				expr_178 = ((int)1);
				
			} else {
				expr_178 = ((int)0);
				
			};
			if ((gate_692 == ((int)0))) {
				expr_177 = ((int)1);
				
			} else {
				expr_177 = ((int)0);
				
			};
			t_sample switch_174 = (expr_178 ? m_history_23 : ((int)0));
			t_sample delta_172 = __m_delta_101(switch_174);
			t_sample sah_171 = __m_sah_102(switch_174, delta_172, ((int)0));
			t_sample switch_170 = (expr_177 ? sah_171 : gate_692);
			t_sample history_176_next_179 = fixdenorm(gate_692);
			int expr_166 = ((int)0);
			int expr_165 = ((int)0);
			if ((gate_693 == ((int)0))) {
				expr_165 = ((int)1);
				
			} else {
				expr_165 = ((int)0);
				
			};
			if ((gate_693 == ((int)0))) {
				expr_166 = ((int)1);
				
			} else {
				expr_166 = ((int)0);
				
			};
			t_sample switch_162 = (expr_166 ? m_history_22 : ((int)0));
			t_sample delta_160 = __m_delta_103(switch_162);
			t_sample sah_159 = __m_sah_104(switch_162, delta_160, ((int)0));
			t_sample switch_158 = (expr_165 ? sah_159 : gate_693);
			t_sample history_164_next_167 = fixdenorm(gate_693);
			int expr_154 = ((int)0);
			int expr_153 = ((int)0);
			if ((gate_694 == ((int)0))) {
				expr_153 = ((int)1);
				
			} else {
				expr_153 = ((int)0);
				
			};
			if ((gate_694 == ((int)0))) {
				expr_154 = ((int)1);
				
			} else {
				expr_154 = ((int)0);
				
			};
			t_sample switch_150 = (expr_154 ? m_history_21 : ((int)0));
			t_sample delta_148 = __m_delta_105(switch_150);
			t_sample sah_147 = __m_sah_106(switch_150, delta_148, ((int)0));
			t_sample switch_146 = (expr_153 ? sah_147 : gate_694);
			t_sample history_152_next_155 = fixdenorm(gate_694);
			int expr_141 = ((int)0);
			int expr_142 = ((int)0);
			if ((gate_695 == ((int)0))) {
				expr_142 = ((int)1);
				
			} else {
				expr_142 = ((int)0);
				
			};
			if ((gate_695 == ((int)0))) {
				expr_141 = ((int)1);
				
			} else {
				expr_141 = ((int)0);
				
			};
			t_sample switch_138 = (expr_142 ? m_history_20 : ((int)0));
			t_sample delta_136 = __m_delta_107(switch_138);
			t_sample sah_135 = __m_sah_108(switch_138, delta_136, ((int)0));
			t_sample switch_134 = (expr_141 ? sah_135 : gate_695);
			t_sample history_140_next_143 = fixdenorm(gate_695);
			int expr_129 = ((int)0);
			int expr_130 = ((int)0);
			if ((gate_696 == ((int)0))) {
				expr_130 = ((int)1);
				
			} else {
				expr_130 = ((int)0);
				
			};
			if ((gate_696 == ((int)0))) {
				expr_129 = ((int)1);
				
			} else {
				expr_129 = ((int)0);
				
			};
			t_sample switch_126 = (expr_130 ? m_history_19 : ((int)0));
			t_sample delta_124 = __m_delta_109(switch_126);
			t_sample sah_123 = __m_sah_110(switch_126, delta_124, ((int)0));
			t_sample switch_122 = (expr_129 ? sah_123 : gate_696);
			t_sample history_128_next_131 = fixdenorm(gate_696);
			int expr_118 = ((int)0);
			int expr_117 = ((int)0);
			if ((gate_697 == ((int)0))) {
				expr_117 = ((int)1);
				
			} else {
				expr_117 = ((int)0);
				
			};
			if ((gate_697 == ((int)0))) {
				expr_118 = ((int)1);
				
			} else {
				expr_118 = ((int)0);
				
			};
			t_sample switch_114 = (expr_118 ? m_history_18 : ((int)0));
			t_sample delta_112 = __m_delta_111(switch_114);
			t_sample sah_111 = __m_sah_112(switch_114, delta_112, ((int)0));
			t_sample switch_110 = (expr_117 ? sah_111 : gate_697);
			t_sample history_116_next_119 = fixdenorm(gate_697);
			int expr_106 = ((int)0);
			int expr_105 = ((int)0);
			if ((gate_698 == ((int)0))) {
				expr_105 = ((int)1);
				
			} else {
				expr_105 = ((int)0);
				
			};
			if ((gate_698 == ((int)0))) {
				expr_106 = ((int)1);
				
			} else {
				expr_106 = ((int)0);
				
			};
			t_sample switch_102 = (expr_106 ? m_history_17 : ((int)0));
			t_sample delta_100 = __m_delta_113(switch_102);
			t_sample sah_99 = __m_sah_114(switch_102, delta_100, ((int)0));
			t_sample switch_98 = (expr_105 ? sah_99 : gate_698);
			t_sample history_104_next_107 = fixdenorm(gate_698);
			int choice_115 = counter_377;
			t_sample gate_683 = (((choice_115 >= 1) && (choice_115 < 2)) ? m_playbackspeed_41 : 0);
			t_sample gate_684 = (((choice_115 >= 2) && (choice_115 < 3)) ? m_playbackspeed_41 : 0);
			t_sample gate_685 = (((choice_115 >= 3) && (choice_115 < 4)) ? m_playbackspeed_41 : 0);
			t_sample gate_686 = (((choice_115 >= 4) && (choice_115 < 5)) ? m_playbackspeed_41 : 0);
			t_sample gate_687 = (((choice_115 >= 5) && (choice_115 < 6)) ? m_playbackspeed_41 : 0);
			t_sample gate_688 = (((choice_115 >= 6) && (choice_115 < 7)) ? m_playbackspeed_41 : 0);
			t_sample gate_689 = (((choice_115 >= 7) && (choice_115 < 8)) ? m_playbackspeed_41 : 0);
			t_sample gate_690 = ((choice_115 >= 8) ? m_playbackspeed_41 : 0);
			int expr_93 = ((int)0);
			int expr_94 = ((int)0);
			if ((gate_683 == ((int)0))) {
				expr_94 = ((int)1);
				
			} else {
				expr_94 = ((int)0);
				
			};
			if ((gate_683 == ((int)0))) {
				expr_93 = ((int)1);
				
			} else {
				expr_93 = ((int)0);
				
			};
			t_sample switch_90 = (expr_94 ? m_history_16 : ((int)0));
			t_sample delta_88 = __m_delta_116(switch_90);
			t_sample sah_87 = __m_sah_117(switch_90, delta_88, ((int)0));
			t_sample switch_86 = (expr_93 ? sah_87 : gate_683);
			t_sample history_92_next_95 = fixdenorm(gate_683);
			t_sample mstosamps_725 = (switch_624 * (samplerate * 0.001));
			t_sample mstosamps_724 = (switch_362 * (samplerate * 0.001));
			int lt_735 = (mstosamps_725 < mstosamps_724);
			int switch_736 = (lt_735 ? ((int)1) : iffalse_118);
			__m_count_119 = (gate_749 ? 0 : (fixdenorm(__m_count_119 + switch_736)));
			int counter_718 = __m_count_119;
			int counter_719 = ((int)0);
			int counter_720 = ((int)0);
			int cond_120 = (counter_718 > ((int)0));
			int expr_18215 = (cond_120 ? ((int)1) : ((int)0));
			int switch_732 = (gate_664 ? counter_718 : ((int)-1));
			bool index_ignore_122 = ((switch_732 >= sampler1_dim) || (switch_732 < 0));
			if ((!(chan_ignore_121 || index_ignore_122))) {
				m_sampler_15.write(gate_757, switch_732, ((int)1));
				
			};
			int switch_733 = (gate_664 ? counter_718 : ((int)-1));
			bool index_ignore_123 = ((switch_733 >= sampler1_dim) || (switch_733 < 0));
			if ((!index_ignore_123)) {
				m_sampler_15.write(gate_765, switch_733, 0);
				
			};
			t_sample sub_4881 = (mstosamps_725 - mstosamps_724);
			t_sample mul_5443 = (sub_4881 * (-1));
			t_sample sub_728 = (switch_362 - switch_624);
			t_sample mstosamps_727 = (sub_728 * (samplerate * 0.001));
			t_sample ltep_726 = ((counter_718 <= mstosamps_727) ? counter_718 : 0);
			t_sample irange_23076 = (mstosamps_724 - ((int)0));
			t_sample orange_23077 = (mstosamps_724 - mstosamps_725);
			t_sample sub_23078 = (ltep_726 - ((int)0));
			t_sample scale_23075 = ((safepow(safediv(sub_23078, irange_23076), ((int)1)) * orange_23077) + mstosamps_725);
			t_sample gtep_717 = ((counter_718 >= mstosamps_727) ? counter_718 : 0);
			t_sample irange_23080 = (((int)0) - mul_5443);
			t_sample orange_23081 = (sub_4881 - ((int)0));
			t_sample sub_23082 = (gtep_717 - mul_5443);
			t_sample scale_23079 = ((safepow(safediv(sub_23082, irange_23080), ((int)1)) * orange_23081) + ((int)0));
			t_sample switch_716 = (expr_18215 ? scale_23075 : scale_23079);
			t_sample mul_734 = (switch_716 * switch_86);
			int index_trunc_124 = fixnan(floor(mul_734));
			double index_fract_125 = (mul_734 - index_trunc_124);
			int index_trunc_126 = (index_trunc_124 + 1);
			int index_wrap_127 = ((index_trunc_124 < 0) ? ((sampler1_dim - 1) + ((index_trunc_124 + 1) % sampler1_dim)) : (index_trunc_124 % sampler1_dim));
			int index_wrap_128 = ((index_trunc_126 < 0) ? ((sampler1_dim - 1) + ((index_trunc_126 + 1) % sampler1_dim)) : (index_trunc_126 % sampler1_dim));
			// samples sampler1 channel 1;
			double read_sampler_130 = m_sampler_15.read(index_wrap_127, chan_wrap_129);
			double read_sampler_131 = m_sampler_15.read(index_wrap_128, chan_wrap_129);
			double readinterp_132 = linear_interp(index_fract_125, read_sampler_130, read_sampler_131);
			t_sample sample_sampler_738 = readinterp_132;
			t_sample index_sampler_739 = mul_734;
			t_sample mul_730 = (switch_182 * sample_sampler_738);
			t_sample clamp_741 = ((mul_730 <= min_133) ? min_133 : ((mul_730 >= ((int)1)) ? ((int)1) : mul_730));
			int index_trunc_134 = fixnan(floor(mul_734));
			double index_fract_135 = (mul_734 - index_trunc_134);
			int index_trunc_136 = (index_trunc_134 + 1);
			int index_wrap_137 = ((index_trunc_134 < 0) ? ((sampler1_dim - 1) + ((index_trunc_134 + 1) % sampler1_dim)) : (index_trunc_134 % sampler1_dim));
			int index_wrap_138 = ((index_trunc_136 < 0) ? ((sampler1_dim - 1) + ((index_trunc_136 + 1) % sampler1_dim)) : (index_trunc_136 % sampler1_dim));
			// samples sampler1 channel 1;
			double read_sampler_139 = m_sampler_15.read(index_wrap_137, 0);
			double read_sampler_140 = m_sampler_15.read(index_wrap_138, 0);
			double readinterp_141 = linear_interp(index_fract_135, read_sampler_139, read_sampler_140);
			t_sample sample_sampler_744 = readinterp_141;
			t_sample index_sampler_745 = mul_734;
			t_sample mul_731 = (switch_182 * sample_sampler_744);
			t_sample clamp_740 = ((mul_731 <= min_142) ? min_142 : ((mul_731 >= ((int)1)) ? ((int)1) : mul_731));
			int expr_81 = ((int)0);
			int expr_82 = ((int)0);
			if ((gate_684 == ((int)0))) {
				expr_82 = ((int)1);
				
			} else {
				expr_82 = ((int)0);
				
			};
			if ((gate_684 == ((int)0))) {
				expr_81 = ((int)1);
				
			} else {
				expr_81 = ((int)0);
				
			};
			t_sample switch_78 = (expr_82 ? m_history_14 : ((int)0));
			t_sample delta_76 = __m_delta_143(switch_78);
			t_sample sah_75 = __m_sah_144(switch_78, delta_76, ((int)0));
			t_sample switch_74 = (expr_81 ? sah_75 : gate_684);
			t_sample history_80_next_83 = fixdenorm(gate_684);
			t_sample mstosamps_599 = (switch_350 * (samplerate * 0.001));
			t_sample mstosamps_598 = (switch_266 * (samplerate * 0.001));
			t_sample sub_6363 = (mstosamps_599 - mstosamps_598);
			int lt_609 = (mstosamps_599 < mstosamps_598);
			int switch_610 = (lt_609 ? ((int)1) : iffalse_145);
			__m_count_146 = (gate_750 ? 0 : (fixdenorm(__m_count_146 + switch_610)));
			int counter_592 = __m_count_146;
			int counter_593 = ((int)0);
			int counter_594 = ((int)0);
			int cond_147 = (counter_592 > ((int)0));
			int expr_7164 = (cond_147 ? ((int)1) : ((int)0));
			int switch_606 = (gate_665 ? counter_592 : ((int)-1));
			bool index_ignore_149 = ((switch_606 >= sampler2_dim) || (switch_606 < 0));
			if ((!(chan_ignore_148 || index_ignore_149))) {
				m_sampler_13.write(gate_758, switch_606, ((int)1));
				
			};
			int switch_607 = (gate_665 ? counter_592 : ((int)-1));
			bool index_ignore_150 = ((switch_607 >= sampler2_dim) || (switch_607 < 0));
			if ((!index_ignore_150)) {
				m_sampler_13.write(gate_766, switch_607, 0);
				
			};
			t_sample mul_6362 = (sub_6363 * (-1));
			t_sample sub_602 = (switch_266 - switch_350);
			t_sample mstosamps_601 = (sub_602 * (samplerate * 0.001));
			t_sample ltep_600 = ((counter_592 <= mstosamps_601) ? counter_592 : 0);
			t_sample irange_23084 = (mstosamps_598 - ((int)0));
			t_sample orange_23085 = (mstosamps_598 - mstosamps_599);
			t_sample sub_23086 = (ltep_600 - ((int)0));
			t_sample scale_23083 = ((safepow(safediv(sub_23086, irange_23084), ((int)1)) * orange_23085) + mstosamps_599);
			t_sample gtep_591 = ((counter_592 >= mstosamps_601) ? counter_592 : 0);
			t_sample irange_23088 = (((int)0) - mul_6362);
			t_sample orange_23089 = (sub_6363 - ((int)0));
			t_sample sub_23090 = (gtep_591 - mul_6362);
			t_sample scale_23087 = ((safepow(safediv(sub_23090, irange_23088), ((int)1)) * orange_23089) + ((int)0));
			t_sample switch_590 = (expr_7164 ? scale_23083 : scale_23087);
			t_sample mul_608 = (switch_590 * switch_74);
			int index_trunc_151 = fixnan(floor(mul_608));
			double index_fract_152 = (mul_608 - index_trunc_151);
			int index_trunc_153 = (index_trunc_151 + 1);
			int index_wrap_154 = ((index_trunc_151 < 0) ? ((sampler2_dim - 1) + ((index_trunc_151 + 1) % sampler2_dim)) : (index_trunc_151 % sampler2_dim));
			int index_wrap_155 = ((index_trunc_153 < 0) ? ((sampler2_dim - 1) + ((index_trunc_153 + 1) % sampler2_dim)) : (index_trunc_153 % sampler2_dim));
			// samples sampler2 channel 1;
			double read_sampler_157 = m_sampler_13.read(index_wrap_154, chan_wrap_156);
			double read_sampler_158 = m_sampler_13.read(index_wrap_155, chan_wrap_156);
			double readinterp_159 = linear_interp(index_fract_152, read_sampler_157, read_sampler_158);
			t_sample sample_sampler_612 = readinterp_159;
			t_sample index_sampler_613 = mul_608;
			t_sample mul_604 = (switch_170 * sample_sampler_612);
			t_sample clamp_615 = ((mul_604 <= min_160) ? min_160 : ((mul_604 >= ((int)1)) ? ((int)1) : mul_604));
			int index_trunc_161 = fixnan(floor(mul_608));
			double index_fract_162 = (mul_608 - index_trunc_161);
			int index_trunc_163 = (index_trunc_161 + 1);
			int index_wrap_164 = ((index_trunc_161 < 0) ? ((sampler2_dim - 1) + ((index_trunc_161 + 1) % sampler2_dim)) : (index_trunc_161 % sampler2_dim));
			int index_wrap_165 = ((index_trunc_163 < 0) ? ((sampler2_dim - 1) + ((index_trunc_163 + 1) % sampler2_dim)) : (index_trunc_163 % sampler2_dim));
			// samples sampler2 channel 1;
			double read_sampler_166 = m_sampler_13.read(index_wrap_164, 0);
			double read_sampler_167 = m_sampler_13.read(index_wrap_165, 0);
			double readinterp_168 = linear_interp(index_fract_162, read_sampler_166, read_sampler_167);
			t_sample sample_sampler_618 = readinterp_168;
			t_sample index_sampler_619 = mul_608;
			t_sample mul_605 = (switch_170 * sample_sampler_618);
			t_sample clamp_614 = ((mul_605 <= min_169) ? min_169 : ((mul_605 >= ((int)1)) ? ((int)1) : mul_605));
			t_sample mix_23091 = (clamp_740 + (((t_sample)0.5) * (clamp_614 - clamp_740)));
			t_sample mix_23092 = (clamp_741 + (((t_sample)0.5) * (clamp_615 - clamp_741)));
			int expr_69 = ((int)0);
			int expr_70 = ((int)0);
			if ((gate_685 == ((int)0))) {
				expr_70 = ((int)1);
				
			} else {
				expr_70 = ((int)0);
				
			};
			if ((gate_685 == ((int)0))) {
				expr_69 = ((int)1);
				
			} else {
				expr_69 = ((int)0);
				
			};
			t_sample switch_66 = (expr_70 ? m_history_12 : ((int)0));
			t_sample delta_64 = __m_delta_170(switch_66);
			t_sample sah_63 = __m_sah_171(switch_66, delta_64, ((int)0));
			t_sample switch_62 = (expr_69 ? sah_63 : gate_685);
			t_sample history_68_next_71 = fixdenorm(gate_685);
			t_sample mstosamps_565 = (switch_338 * (samplerate * 0.001));
			t_sample mstosamps_564 = (switch_254 * (samplerate * 0.001));
			t_sample sub_7766 = (mstosamps_565 - mstosamps_564);
			int lt_575 = (mstosamps_565 < mstosamps_564);
			int switch_576 = (lt_575 ? ((int)1) : iffalse_172);
			__m_count_173 = (gate_751 ? 0 : (fixdenorm(__m_count_173 + switch_576)));
			int counter_558 = __m_count_173;
			int counter_559 = ((int)0);
			int counter_560 = ((int)0);
			int cond_174 = (counter_558 > ((int)0));
			int expr_8064 = (cond_174 ? ((int)1) : ((int)0));
			int switch_572 = (gate_666 ? counter_558 : ((int)-1));
			bool index_ignore_176 = ((switch_572 >= sampler3_dim) || (switch_572 < 0));
			if ((!(chan_ignore_175 || index_ignore_176))) {
				m_sampler_11.write(gate_759, switch_572, ((int)1));
				
			};
			int switch_573 = (gate_666 ? counter_558 : ((int)-1));
			bool index_ignore_177 = ((switch_573 >= sampler3_dim) || (switch_573 < 0));
			if ((!index_ignore_177)) {
				m_sampler_11.write(gate_767, switch_573, 0);
				
			};
			t_sample mul_7765 = (sub_7766 * (-1));
			t_sample sub_568 = (switch_254 - switch_338);
			t_sample mstosamps_567 = (sub_568 * (samplerate * 0.001));
			t_sample ltep_566 = ((counter_558 <= mstosamps_567) ? counter_558 : 0);
			t_sample irange_23094 = (mstosamps_564 - ((int)0));
			t_sample orange_23095 = (mstosamps_564 - mstosamps_565);
			t_sample sub_23096 = (ltep_566 - ((int)0));
			t_sample scale_23093 = ((safepow(safediv(sub_23096, irange_23094), ((int)1)) * orange_23095) + mstosamps_565);
			t_sample gtep_557 = ((counter_558 >= mstosamps_567) ? counter_558 : 0);
			t_sample irange_23098 = (((int)0) - mul_7765);
			t_sample orange_23099 = (sub_7766 - ((int)0));
			t_sample sub_23100 = (gtep_557 - mul_7765);
			t_sample scale_23097 = ((safepow(safediv(sub_23100, irange_23098), ((int)1)) * orange_23099) + ((int)0));
			t_sample switch_556 = (expr_8064 ? scale_23093 : scale_23097);
			t_sample mul_574 = (switch_556 * switch_62);
			int index_trunc_178 = fixnan(floor(mul_574));
			double index_fract_179 = (mul_574 - index_trunc_178);
			int index_trunc_180 = (index_trunc_178 + 1);
			int index_wrap_181 = ((index_trunc_178 < 0) ? ((sampler3_dim - 1) + ((index_trunc_178 + 1) % sampler3_dim)) : (index_trunc_178 % sampler3_dim));
			int index_wrap_182 = ((index_trunc_180 < 0) ? ((sampler3_dim - 1) + ((index_trunc_180 + 1) % sampler3_dim)) : (index_trunc_180 % sampler3_dim));
			// samples sampler3 channel 1;
			double read_sampler_184 = m_sampler_11.read(index_wrap_181, chan_wrap_183);
			double read_sampler_185 = m_sampler_11.read(index_wrap_182, chan_wrap_183);
			double readinterp_186 = linear_interp(index_fract_179, read_sampler_184, read_sampler_185);
			t_sample sample_sampler_578 = readinterp_186;
			t_sample index_sampler_579 = mul_574;
			t_sample mul_570 = (switch_158 * sample_sampler_578);
			t_sample clamp_581 = ((mul_570 <= min_187) ? min_187 : ((mul_570 >= ((int)1)) ? ((int)1) : mul_570));
			int index_trunc_188 = fixnan(floor(mul_574));
			double index_fract_189 = (mul_574 - index_trunc_188);
			int index_trunc_190 = (index_trunc_188 + 1);
			int index_wrap_191 = ((index_trunc_188 < 0) ? ((sampler3_dim - 1) + ((index_trunc_188 + 1) % sampler3_dim)) : (index_trunc_188 % sampler3_dim));
			int index_wrap_192 = ((index_trunc_190 < 0) ? ((sampler3_dim - 1) + ((index_trunc_190 + 1) % sampler3_dim)) : (index_trunc_190 % sampler3_dim));
			// samples sampler3 channel 1;
			double read_sampler_193 = m_sampler_11.read(index_wrap_191, 0);
			double read_sampler_194 = m_sampler_11.read(index_wrap_192, 0);
			double readinterp_195 = linear_interp(index_fract_189, read_sampler_193, read_sampler_194);
			t_sample sample_sampler_584 = readinterp_195;
			t_sample index_sampler_585 = mul_574;
			t_sample mul_571 = (switch_158 * sample_sampler_584);
			t_sample clamp_580 = ((mul_571 <= min_196) ? min_196 : ((mul_571 >= ((int)1)) ? ((int)1) : mul_571));
			int expr_57 = ((int)0);
			int expr_58 = ((int)0);
			if ((gate_686 == ((int)0))) {
				expr_58 = ((int)1);
				
			} else {
				expr_58 = ((int)0);
				
			};
			if ((gate_686 == ((int)0))) {
				expr_57 = ((int)1);
				
			} else {
				expr_57 = ((int)0);
				
			};
			t_sample switch_54 = (expr_58 ? m_history_10 : ((int)0));
			t_sample delta_52 = __m_delta_197(switch_54);
			t_sample sah_51 = __m_sah_198(switch_54, delta_52, ((int)0));
			t_sample switch_50 = (expr_57 ? sah_51 : gate_686);
			t_sample history_56_next_59 = fixdenorm(gate_686);
			t_sample mstosamps_531 = (switch_326 * (samplerate * 0.001));
			t_sample mstosamps_530 = (switch_242 * (samplerate * 0.001));
			t_sample sub_8754 = (mstosamps_531 - mstosamps_530);
			int lt_541 = (mstosamps_531 < mstosamps_530);
			int switch_542 = (lt_541 ? ((int)1) : iffalse_199);
			__m_count_200 = (gate_752 ? 0 : (fixdenorm(__m_count_200 + switch_542)));
			int counter_524 = __m_count_200;
			int counter_525 = ((int)0);
			int counter_526 = ((int)0);
			int cond_201 = (counter_524 > ((int)0));
			int expr_9092 = (cond_201 ? ((int)1) : ((int)0));
			int switch_538 = (gate_667 ? counter_524 : ((int)-1));
			bool index_ignore_203 = ((switch_538 >= sampler4_dim) || (switch_538 < 0));
			if ((!(chan_ignore_202 || index_ignore_203))) {
				m_sampler_9.write(gate_760, switch_538, ((int)1));
				
			};
			int switch_539 = (gate_667 ? counter_524 : ((int)-1));
			bool index_ignore_204 = ((switch_539 >= sampler4_dim) || (switch_539 < 0));
			if ((!index_ignore_204)) {
				m_sampler_9.write(gate_768, switch_539, 0);
				
			};
			t_sample mul_8753 = (sub_8754 * (-1));
			t_sample sub_534 = (switch_242 - switch_326);
			t_sample mstosamps_533 = (sub_534 * (samplerate * 0.001));
			t_sample ltep_532 = ((counter_524 <= mstosamps_533) ? counter_524 : 0);
			t_sample irange_23102 = (mstosamps_530 - ((int)0));
			t_sample orange_23103 = (mstosamps_530 - mstosamps_531);
			t_sample sub_23104 = (ltep_532 - ((int)0));
			t_sample scale_23101 = ((safepow(safediv(sub_23104, irange_23102), ((int)1)) * orange_23103) + mstosamps_531);
			t_sample gtep_523 = ((counter_524 >= mstosamps_533) ? counter_524 : 0);
			t_sample irange_23106 = (((int)0) - mul_8753);
			t_sample orange_23107 = (sub_8754 - ((int)0));
			t_sample sub_23108 = (gtep_523 - mul_8753);
			t_sample scale_23105 = ((safepow(safediv(sub_23108, irange_23106), ((int)1)) * orange_23107) + ((int)0));
			t_sample switch_522 = (expr_9092 ? scale_23101 : scale_23105);
			t_sample mul_540 = (switch_522 * switch_50);
			int index_trunc_205 = fixnan(floor(mul_540));
			double index_fract_206 = (mul_540 - index_trunc_205);
			int index_trunc_207 = (index_trunc_205 + 1);
			int index_wrap_208 = ((index_trunc_205 < 0) ? ((sampler4_dim - 1) + ((index_trunc_205 + 1) % sampler4_dim)) : (index_trunc_205 % sampler4_dim));
			int index_wrap_209 = ((index_trunc_207 < 0) ? ((sampler4_dim - 1) + ((index_trunc_207 + 1) % sampler4_dim)) : (index_trunc_207 % sampler4_dim));
			// samples sampler4 channel 1;
			double read_sampler_210 = m_sampler_9.read(index_wrap_208, 0);
			double read_sampler_211 = m_sampler_9.read(index_wrap_209, 0);
			double readinterp_212 = linear_interp(index_fract_206, read_sampler_210, read_sampler_211);
			t_sample sample_sampler_550 = readinterp_212;
			t_sample index_sampler_551 = mul_540;
			t_sample mul_537 = (switch_146 * sample_sampler_550);
			t_sample clamp_546 = ((mul_537 <= min_213) ? min_213 : ((mul_537 >= ((int)1)) ? ((int)1) : mul_537));
			int index_trunc_214 = fixnan(floor(mul_540));
			double index_fract_215 = (mul_540 - index_trunc_214);
			int index_trunc_216 = (index_trunc_214 + 1);
			int index_wrap_217 = ((index_trunc_214 < 0) ? ((sampler4_dim - 1) + ((index_trunc_214 + 1) % sampler4_dim)) : (index_trunc_214 % sampler4_dim));
			int index_wrap_218 = ((index_trunc_216 < 0) ? ((sampler4_dim - 1) + ((index_trunc_216 + 1) % sampler4_dim)) : (index_trunc_216 % sampler4_dim));
			// samples sampler4 channel 1;
			double read_sampler_220 = m_sampler_9.read(index_wrap_217, chan_wrap_219);
			double read_sampler_221 = m_sampler_9.read(index_wrap_218, chan_wrap_219);
			double readinterp_222 = linear_interp(index_fract_215, read_sampler_220, read_sampler_221);
			t_sample sample_sampler_544 = readinterp_222;
			t_sample index_sampler_545 = mul_540;
			t_sample mul_536 = (switch_146 * sample_sampler_544);
			t_sample clamp_547 = ((mul_536 <= min_223) ? min_223 : ((mul_536 >= ((int)1)) ? ((int)1) : mul_536));
			t_sample mix_23109 = (clamp_580 + (((t_sample)0.5) * (clamp_546 - clamp_580)));
			t_sample mix_23110 = (mix_23091 + (((t_sample)0.5) * (mix_23109 - mix_23091)));
			t_sample mix_23111 = (clamp_581 + (((t_sample)0.5) * (clamp_547 - clamp_581)));
			t_sample mix_23112 = (mix_23092 + (((t_sample)0.5) * (mix_23111 - mix_23092)));
			int expr_45 = ((int)0);
			int expr_46 = ((int)0);
			if ((gate_687 == ((int)0))) {
				expr_46 = ((int)1);
				
			} else {
				expr_46 = ((int)0);
				
			};
			if ((gate_687 == ((int)0))) {
				expr_45 = ((int)1);
				
			} else {
				expr_45 = ((int)0);
				
			};
			t_sample switch_42 = (expr_46 ? m_history_8 : ((int)0));
			t_sample delta_40 = __m_delta_224(switch_42);
			t_sample sah_39 = __m_sah_225(switch_42, delta_40, ((int)0));
			t_sample switch_38 = (expr_45 ? sah_39 : gate_687);
			t_sample history_44_next_47 = fixdenorm(gate_687);
			t_sample mstosamps_497 = (switch_314 * (samplerate * 0.001));
			t_sample mstosamps_496 = (switch_230 * (samplerate * 0.001));
			t_sample sub_9800 = (mstosamps_497 - mstosamps_496);
			int lt_507 = (mstosamps_497 < mstosamps_496);
			int switch_508 = (lt_507 ? ((int)1) : iffalse_226);
			__m_count_227 = (gate_753 ? 0 : (fixdenorm(__m_count_227 + switch_508)));
			int counter_490 = __m_count_227;
			int counter_491 = ((int)0);
			int counter_492 = ((int)0);
			int cond_228 = (counter_490 > ((int)0));
			int expr_10178 = (cond_228 ? ((int)1) : ((int)0));
			int switch_505 = (gate_668 ? counter_490 : ((int)-1));
			bool index_ignore_229 = ((switch_505 >= sampler5_dim) || (switch_505 < 0));
			if ((!index_ignore_229)) {
				m_sampler_7.write(gate_769, switch_505, 0);
				
			};
			int switch_504 = (gate_668 ? counter_490 : ((int)-1));
			bool index_ignore_231 = ((switch_504 >= sampler5_dim) || (switch_504 < 0));
			if ((!(chan_ignore_230 || index_ignore_231))) {
				m_sampler_7.write(gate_761, switch_504, ((int)1));
				
			};
			t_sample mul_9799 = (sub_9800 * (-1));
			t_sample sub_500 = (switch_230 - switch_314);
			t_sample mstosamps_499 = (sub_500 * (samplerate * 0.001));
			t_sample ltep_498 = ((counter_490 <= mstosamps_499) ? counter_490 : 0);
			t_sample irange_23114 = (mstosamps_496 - ((int)0));
			t_sample orange_23115 = (mstosamps_496 - mstosamps_497);
			t_sample sub_23116 = (ltep_498 - ((int)0));
			t_sample scale_23113 = ((safepow(safediv(sub_23116, irange_23114), ((int)1)) * orange_23115) + mstosamps_497);
			t_sample gtep_489 = ((counter_490 >= mstosamps_499) ? counter_490 : 0);
			t_sample irange_23118 = (((int)0) - mul_9799);
			t_sample orange_23119 = (sub_9800 - ((int)0));
			t_sample sub_23120 = (gtep_489 - mul_9799);
			t_sample scale_23117 = ((safepow(safediv(sub_23120, irange_23118), ((int)1)) * orange_23119) + ((int)0));
			t_sample switch_488 = (expr_10178 ? scale_23113 : scale_23117);
			t_sample mul_506 = (switch_488 * switch_38);
			int index_trunc_232 = fixnan(floor(mul_506));
			double index_fract_233 = (mul_506 - index_trunc_232);
			int index_trunc_234 = (index_trunc_232 + 1);
			int index_wrap_235 = ((index_trunc_232 < 0) ? ((sampler5_dim - 1) + ((index_trunc_232 + 1) % sampler5_dim)) : (index_trunc_232 % sampler5_dim));
			int index_wrap_236 = ((index_trunc_234 < 0) ? ((sampler5_dim - 1) + ((index_trunc_234 + 1) % sampler5_dim)) : (index_trunc_234 % sampler5_dim));
			// samples sampler5 channel 1;
			double read_sampler_237 = m_sampler_7.read(index_wrap_235, 0);
			double read_sampler_238 = m_sampler_7.read(index_wrap_236, 0);
			double readinterp_239 = linear_interp(index_fract_233, read_sampler_237, read_sampler_238);
			t_sample sample_sampler_516 = readinterp_239;
			t_sample index_sampler_517 = mul_506;
			t_sample mul_503 = (switch_134 * sample_sampler_516);
			t_sample clamp_512 = ((mul_503 <= min_240) ? min_240 : ((mul_503 >= ((int)1)) ? ((int)1) : mul_503));
			int index_trunc_241 = fixnan(floor(mul_506));
			double index_fract_242 = (mul_506 - index_trunc_241);
			int index_trunc_243 = (index_trunc_241 + 1);
			int index_wrap_244 = ((index_trunc_241 < 0) ? ((sampler5_dim - 1) + ((index_trunc_241 + 1) % sampler5_dim)) : (index_trunc_241 % sampler5_dim));
			int index_wrap_245 = ((index_trunc_243 < 0) ? ((sampler5_dim - 1) + ((index_trunc_243 + 1) % sampler5_dim)) : (index_trunc_243 % sampler5_dim));
			// samples sampler5 channel 1;
			double read_sampler_247 = m_sampler_7.read(index_wrap_244, chan_wrap_246);
			double read_sampler_248 = m_sampler_7.read(index_wrap_245, chan_wrap_246);
			double readinterp_249 = linear_interp(index_fract_242, read_sampler_247, read_sampler_248);
			t_sample sample_sampler_510 = readinterp_249;
			t_sample index_sampler_511 = mul_506;
			t_sample mul_502 = (switch_134 * sample_sampler_510);
			t_sample clamp_513 = ((mul_502 <= min_250) ? min_250 : ((mul_502 >= ((int)1)) ? ((int)1) : mul_502));
			int expr_33 = ((int)0);
			int expr_34 = ((int)0);
			if ((gate_688 == ((int)0))) {
				expr_34 = ((int)1);
				
			} else {
				expr_34 = ((int)0);
				
			};
			if ((gate_688 == ((int)0))) {
				expr_33 = ((int)1);
				
			} else {
				expr_33 = ((int)0);
				
			};
			t_sample switch_30 = (expr_34 ? m_history_6 : ((int)0));
			t_sample delta_28 = __m_delta_251(switch_30);
			t_sample sah_27 = __m_sah_252(switch_30, delta_28, ((int)0));
			t_sample switch_26 = (expr_33 ? sah_27 : gate_688);
			t_sample history_32_next_35 = fixdenorm(gate_688);
			t_sample mstosamps_463 = (switch_302 * (samplerate * 0.001));
			t_sample mstosamps_462 = (switch_218 * (samplerate * 0.001));
			t_sample sub_11301 = (mstosamps_463 - mstosamps_462);
			int lt_473 = (mstosamps_463 < mstosamps_462);
			int switch_474 = (lt_473 ? ((int)1) : iffalse_253);
			__m_count_254 = (gate_754 ? 0 : (fixdenorm(__m_count_254 + switch_474)));
			int counter_456 = __m_count_254;
			int counter_457 = ((int)0);
			int counter_458 = ((int)0);
			int cond_255 = (counter_456 > ((int)0));
			int expr_11719 = (cond_255 ? ((int)1) : ((int)0));
			int switch_471 = (gate_669 ? counter_456 : ((int)-1));
			bool index_ignore_256 = ((switch_471 >= sampler6_dim) || (switch_471 < 0));
			if ((!index_ignore_256)) {
				m_sampler_5.write(gate_770, switch_471, 0);
				
			};
			int switch_470 = (gate_669 ? counter_456 : ((int)-1));
			bool index_ignore_258 = ((switch_470 >= sampler6_dim) || (switch_470 < 0));
			if ((!(chan_ignore_257 || index_ignore_258))) {
				m_sampler_5.write(gate_762, switch_470, ((int)1));
				
			};
			t_sample mul_11300 = (sub_11301 * (-1));
			t_sample sub_466 = (switch_218 - switch_302);
			t_sample mstosamps_465 = (sub_466 * (samplerate * 0.001));
			t_sample ltep_464 = ((counter_456 <= mstosamps_465) ? counter_456 : 0);
			t_sample irange_23122 = (mstosamps_462 - ((int)0));
			t_sample orange_23123 = (mstosamps_462 - mstosamps_463);
			t_sample sub_23124 = (ltep_464 - ((int)0));
			t_sample scale_23121 = ((safepow(safediv(sub_23124, irange_23122), ((int)1)) * orange_23123) + mstosamps_463);
			t_sample gtep_455 = ((counter_456 >= mstosamps_465) ? counter_456 : 0);
			t_sample irange_23126 = (((int)0) - mul_11300);
			t_sample orange_23127 = (sub_11301 - ((int)0));
			t_sample sub_23128 = (gtep_455 - mul_11300);
			t_sample scale_23125 = ((safepow(safediv(sub_23128, irange_23126), ((int)1)) * orange_23127) + ((int)0));
			t_sample switch_454 = (expr_11719 ? scale_23121 : scale_23125);
			t_sample mul_472 = (switch_454 * switch_26);
			int index_trunc_259 = fixnan(floor(mul_472));
			double index_fract_260 = (mul_472 - index_trunc_259);
			int index_trunc_261 = (index_trunc_259 + 1);
			int index_wrap_262 = ((index_trunc_259 < 0) ? ((sampler6_dim - 1) + ((index_trunc_259 + 1) % sampler6_dim)) : (index_trunc_259 % sampler6_dim));
			int index_wrap_263 = ((index_trunc_261 < 0) ? ((sampler6_dim - 1) + ((index_trunc_261 + 1) % sampler6_dim)) : (index_trunc_261 % sampler6_dim));
			// samples sampler6 channel 1;
			double read_sampler_265 = m_sampler_5.read(index_wrap_262, chan_wrap_264);
			double read_sampler_266 = m_sampler_5.read(index_wrap_263, chan_wrap_264);
			double readinterp_267 = linear_interp(index_fract_260, read_sampler_265, read_sampler_266);
			t_sample sample_sampler_476 = readinterp_267;
			t_sample index_sampler_477 = mul_472;
			t_sample mul_468 = (switch_122 * sample_sampler_476);
			t_sample clamp_479 = ((mul_468 <= min_268) ? min_268 : ((mul_468 >= ((int)1)) ? ((int)1) : mul_468));
			int index_trunc_269 = fixnan(floor(mul_472));
			double index_fract_270 = (mul_472 - index_trunc_269);
			int index_trunc_271 = (index_trunc_269 + 1);
			int index_wrap_272 = ((index_trunc_269 < 0) ? ((sampler6_dim - 1) + ((index_trunc_269 + 1) % sampler6_dim)) : (index_trunc_269 % sampler6_dim));
			int index_wrap_273 = ((index_trunc_271 < 0) ? ((sampler6_dim - 1) + ((index_trunc_271 + 1) % sampler6_dim)) : (index_trunc_271 % sampler6_dim));
			// samples sampler6 channel 1;
			double read_sampler_274 = m_sampler_5.read(index_wrap_272, 0);
			double read_sampler_275 = m_sampler_5.read(index_wrap_273, 0);
			double readinterp_276 = linear_interp(index_fract_270, read_sampler_274, read_sampler_275);
			t_sample sample_sampler_482 = readinterp_276;
			t_sample index_sampler_483 = mul_472;
			t_sample mul_469 = (switch_122 * sample_sampler_482);
			t_sample clamp_478 = ((mul_469 <= min_277) ? min_277 : ((mul_469 >= ((int)1)) ? ((int)1) : mul_469));
			t_sample mix_23129 = (clamp_512 + (((t_sample)0.5) * (clamp_478 - clamp_512)));
			t_sample mix_23130 = (clamp_513 + (((t_sample)0.5) * (clamp_479 - clamp_513)));
			int expr_22 = ((int)0);
			int expr_21 = ((int)0);
			if ((gate_689 == ((int)0))) {
				expr_21 = ((int)1);
				
			} else {
				expr_21 = ((int)0);
				
			};
			if ((gate_689 == ((int)0))) {
				expr_22 = ((int)1);
				
			} else {
				expr_22 = ((int)0);
				
			};
			t_sample switch_18 = (expr_22 ? m_history_4 : ((int)0));
			t_sample delta_16 = __m_delta_278(switch_18);
			t_sample sah_15 = __m_sah_279(switch_18, delta_16, ((int)0));
			t_sample switch_14 = (expr_21 ? sah_15 : gate_689);
			t_sample history_20_next_23 = fixdenorm(gate_689);
			t_sample mstosamps_429 = (switch_290 * (samplerate * 0.001));
			t_sample mstosamps_428 = (switch_206 * (samplerate * 0.001));
			t_sample sub_12587 = (mstosamps_429 - mstosamps_428);
			int lt_439 = (mstosamps_429 < mstosamps_428);
			int switch_440 = (lt_439 ? ((int)1) : iffalse_280);
			__m_count_281 = (gate_755 ? 0 : (fixdenorm(__m_count_281 + switch_440)));
			int counter_422 = __m_count_281;
			int counter_423 = ((int)0);
			int counter_424 = ((int)0);
			int cond_282 = (counter_422 > ((int)0));
			int expr_13045 = (cond_282 ? ((int)1) : ((int)0));
			int switch_437 = (gate_670 ? counter_422 : ((int)-1));
			bool index_ignore_283 = ((switch_437 >= sampler7_dim) || (switch_437 < 0));
			if ((!index_ignore_283)) {
				m_sampler_3.write(gate_771, switch_437, 0);
				
			};
			int switch_436 = (gate_670 ? counter_422 : ((int)-1));
			bool index_ignore_285 = ((switch_436 >= sampler7_dim) || (switch_436 < 0));
			if ((!(chan_ignore_284 || index_ignore_285))) {
				m_sampler_3.write(gate_763, switch_436, ((int)1));
				
			};
			t_sample mul_12586 = (sub_12587 * (-1));
			t_sample sub_432 = (switch_206 - switch_290);
			t_sample mstosamps_431 = (sub_432 * (samplerate * 0.001));
			t_sample ltep_430 = ((counter_422 <= mstosamps_431) ? counter_422 : 0);
			t_sample irange_23132 = (mstosamps_428 - ((int)0));
			t_sample orange_23133 = (mstosamps_428 - mstosamps_429);
			t_sample sub_23134 = (ltep_430 - ((int)0));
			t_sample scale_23131 = ((safepow(safediv(sub_23134, irange_23132), ((int)1)) * orange_23133) + mstosamps_429);
			t_sample gtep_421 = ((counter_422 >= mstosamps_431) ? counter_422 : 0);
			t_sample irange_23136 = (((int)0) - mul_12586);
			t_sample orange_23137 = (sub_12587 - ((int)0));
			t_sample sub_23138 = (gtep_421 - mul_12586);
			t_sample scale_23135 = ((safepow(safediv(sub_23138, irange_23136), ((int)1)) * orange_23137) + ((int)0));
			t_sample switch_420 = (expr_13045 ? scale_23131 : scale_23135);
			t_sample mul_438 = (switch_420 * switch_14);
			int index_trunc_286 = fixnan(floor(mul_438));
			double index_fract_287 = (mul_438 - index_trunc_286);
			int index_trunc_288 = (index_trunc_286 + 1);
			int index_wrap_289 = ((index_trunc_286 < 0) ? ((sampler7_dim - 1) + ((index_trunc_286 + 1) % sampler7_dim)) : (index_trunc_286 % sampler7_dim));
			int index_wrap_290 = ((index_trunc_288 < 0) ? ((sampler7_dim - 1) + ((index_trunc_288 + 1) % sampler7_dim)) : (index_trunc_288 % sampler7_dim));
			// samples sampler7 channel 1;
			double read_sampler_292 = m_sampler_3.read(index_wrap_289, chan_wrap_291);
			double read_sampler_293 = m_sampler_3.read(index_wrap_290, chan_wrap_291);
			double readinterp_294 = linear_interp(index_fract_287, read_sampler_292, read_sampler_293);
			t_sample sample_sampler_442 = readinterp_294;
			t_sample index_sampler_443 = mul_438;
			t_sample mul_434 = (switch_110 * sample_sampler_442);
			t_sample clamp_445 = ((mul_434 <= min_295) ? min_295 : ((mul_434 >= ((int)1)) ? ((int)1) : mul_434));
			int index_trunc_296 = fixnan(floor(mul_438));
			double index_fract_297 = (mul_438 - index_trunc_296);
			int index_trunc_298 = (index_trunc_296 + 1);
			int index_wrap_299 = ((index_trunc_296 < 0) ? ((sampler7_dim - 1) + ((index_trunc_296 + 1) % sampler7_dim)) : (index_trunc_296 % sampler7_dim));
			int index_wrap_300 = ((index_trunc_298 < 0) ? ((sampler7_dim - 1) + ((index_trunc_298 + 1) % sampler7_dim)) : (index_trunc_298 % sampler7_dim));
			// samples sampler7 channel 1;
			double read_sampler_301 = m_sampler_3.read(index_wrap_299, 0);
			double read_sampler_302 = m_sampler_3.read(index_wrap_300, 0);
			double readinterp_303 = linear_interp(index_fract_297, read_sampler_301, read_sampler_302);
			t_sample sample_sampler_448 = readinterp_303;
			t_sample index_sampler_449 = mul_438;
			t_sample mul_435 = (switch_110 * sample_sampler_448);
			t_sample clamp_444 = ((mul_435 <= min_304) ? min_304 : ((mul_435 >= ((int)1)) ? ((int)1) : mul_435));
			int expr_10 = ((int)0);
			int expr_9 = ((int)0);
			if ((gate_690 == ((int)0))) {
				expr_9 = ((int)1);
				
			} else {
				expr_9 = ((int)0);
				
			};
			if ((gate_690 == ((int)0))) {
				expr_10 = ((int)1);
				
			} else {
				expr_10 = ((int)0);
				
			};
			t_sample switch_6 = (expr_10 ? m_history_2 : ((int)0));
			t_sample delta_4 = __m_delta_305(switch_6);
			t_sample sah_3 = __m_sah_306(switch_6, delta_4, ((int)0));
			t_sample switch_2 = (expr_9 ? sah_3 : gate_690);
			t_sample history_8_next_11 = fixdenorm(gate_690);
			t_sample mstosamps_395 = (switch_278 * (samplerate * 0.001));
			t_sample mstosamps_394 = (switch_194 * (samplerate * 0.001));
			t_sample sub_13993 = (mstosamps_395 - mstosamps_394);
			int lt_405 = (mstosamps_395 < mstosamps_394);
			int switch_406 = (lt_405 ? ((int)1) : iffalse_307);
			__m_count_308 = (gate_756 ? 0 : (fixdenorm(__m_count_308 + switch_406)));
			int counter_388 = __m_count_308;
			int counter_389 = ((int)0);
			int counter_390 = ((int)0);
			int cond_309 = (counter_388 > ((int)0));
			int expr_14491 = (cond_309 ? ((int)1) : ((int)0));
			int switch_403 = (gate_671 ? counter_388 : ((int)-1));
			bool index_ignore_310 = ((switch_403 >= sampler8_dim) || (switch_403 < 0));
			if ((!index_ignore_310)) {
				m_sampler_1.write(gate_772, switch_403, 0);
				
			};
			int switch_402 = (gate_671 ? counter_388 : ((int)-1));
			bool index_ignore_312 = ((switch_402 >= sampler8_dim) || (switch_402 < 0));
			if ((!(chan_ignore_311 || index_ignore_312))) {
				m_sampler_1.write(gate_764, switch_402, ((int)1));
				
			};
			t_sample mul_13992 = (sub_13993 * (-1));
			t_sample sub_398 = (switch_194 - switch_278);
			t_sample mstosamps_397 = (sub_398 * (samplerate * 0.001));
			t_sample ltep_396 = ((counter_388 <= mstosamps_397) ? counter_388 : 0);
			t_sample irange_23140 = (mstosamps_394 - ((int)0));
			t_sample orange_23141 = (mstosamps_394 - mstosamps_395);
			t_sample sub_23142 = (ltep_396 - ((int)0));
			t_sample scale_23139 = ((safepow(safediv(sub_23142, irange_23140), ((int)1)) * orange_23141) + mstosamps_395);
			t_sample gtep_387 = ((counter_388 >= mstosamps_397) ? counter_388 : 0);
			t_sample irange_23144 = (((int)0) - mul_13992);
			t_sample orange_23145 = (sub_13993 - ((int)0));
			t_sample sub_23146 = (gtep_387 - mul_13992);
			t_sample scale_23143 = ((safepow(safediv(sub_23146, irange_23144), ((int)1)) * orange_23145) + ((int)0));
			t_sample switch_386 = (expr_14491 ? scale_23139 : scale_23143);
			t_sample mul_404 = (switch_386 * switch_2);
			int index_trunc_313 = fixnan(floor(mul_404));
			double index_fract_314 = (mul_404 - index_trunc_313);
			int index_trunc_315 = (index_trunc_313 + 1);
			int index_wrap_316 = ((index_trunc_313 < 0) ? ((sampler8_dim - 1) + ((index_trunc_313 + 1) % sampler8_dim)) : (index_trunc_313 % sampler8_dim));
			int index_wrap_317 = ((index_trunc_315 < 0) ? ((sampler8_dim - 1) + ((index_trunc_315 + 1) % sampler8_dim)) : (index_trunc_315 % sampler8_dim));
			// samples sampler8 channel 1;
			double read_sampler_319 = m_sampler_1.read(index_wrap_316, chan_wrap_318);
			double read_sampler_320 = m_sampler_1.read(index_wrap_317, chan_wrap_318);
			double readinterp_321 = linear_interp(index_fract_314, read_sampler_319, read_sampler_320);
			t_sample sample_sampler_408 = readinterp_321;
			t_sample index_sampler_409 = mul_404;
			t_sample mul_400 = (switch_98 * sample_sampler_408);
			t_sample clamp_411 = ((mul_400 <= min_322) ? min_322 : ((mul_400 >= ((int)1)) ? ((int)1) : mul_400));
			int index_trunc_323 = fixnan(floor(mul_404));
			double index_fract_324 = (mul_404 - index_trunc_323);
			int index_trunc_325 = (index_trunc_323 + 1);
			int index_wrap_326 = ((index_trunc_323 < 0) ? ((sampler8_dim - 1) + ((index_trunc_323 + 1) % sampler8_dim)) : (index_trunc_323 % sampler8_dim));
			int index_wrap_327 = ((index_trunc_325 < 0) ? ((sampler8_dim - 1) + ((index_trunc_325 + 1) % sampler8_dim)) : (index_trunc_325 % sampler8_dim));
			// samples sampler8 channel 1;
			double read_sampler_328 = m_sampler_1.read(index_wrap_326, 0);
			double read_sampler_329 = m_sampler_1.read(index_wrap_327, 0);
			double readinterp_330 = linear_interp(index_fract_324, read_sampler_328, read_sampler_329);
			t_sample sample_sampler_414 = readinterp_330;
			t_sample index_sampler_415 = mul_404;
			t_sample mul_401 = (switch_98 * sample_sampler_414);
			t_sample clamp_410 = ((mul_401 <= min_331) ? min_331 : ((mul_401 >= ((int)1)) ? ((int)1) : mul_401));
			t_sample mix_23147 = (clamp_444 + (((t_sample)0.5) * (clamp_410 - clamp_444)));
			t_sample mix_23148 = (mix_23129 + (((t_sample)0.5) * (mix_23147 - mix_23129)));
			t_sample mix_23149 = (mix_23110 + (((t_sample)0.5) * (mix_23148 - mix_23110)));
			t_sample clamp_682 = ((mix_23149 <= min_332) ? min_332 : ((mix_23149 >= ((int)1)) ? ((int)1) : mix_23149));
			t_sample mix_23150 = (in1 + (m_wetdry_45 * (clamp_682 - in1)));
			t_sample out1 = mix_23150;
			t_sample mix_23151 = (clamp_445 + (((t_sample)0.5) * (clamp_411 - clamp_445)));
			t_sample mix_23152 = (mix_23130 + (((t_sample)0.5) * (mix_23151 - mix_23130)));
			t_sample mix_23153 = (mix_23112 + (((t_sample)0.5) * (mix_23152 - mix_23112)));
			t_sample clamp_681 = ((mix_23153 <= min_333) ? min_333 : ((mix_23153 >= ((int)1)) ? ((int)1) : mix_23153));
			t_sample mix_23154 = (in2 + (m_wetdry_45 * (clamp_681 - in2)));
			t_sample out2 = mix_23154;
			m_history_40 = history_630_next_633;
			m_history_39 = history_356_next_359;
			m_history_38 = history_344_next_347;
			m_history_37 = history_332_next_335;
			m_history_36 = history_320_next_323;
			m_history_35 = history_308_next_311;
			m_history_34 = history_296_next_299;
			m_history_33 = history_284_next_287;
			m_history_32 = history_368_next_371;
			m_history_31 = history_272_next_275;
			m_history_30 = history_260_next_263;
			m_history_29 = history_248_next_251;
			m_history_28 = history_236_next_239;
			m_history_27 = history_224_next_227;
			m_history_26 = history_212_next_215;
			m_history_25 = history_200_next_203;
			m_history_24 = history_188_next_191;
			m_history_23 = history_176_next_179;
			m_history_22 = history_164_next_167;
			m_history_21 = history_152_next_155;
			m_history_20 = history_140_next_143;
			m_history_19 = history_128_next_131;
			m_history_18 = history_116_next_119;
			m_history_17 = history_104_next_107;
			m_history_16 = history_92_next_95;
			m_history_14 = history_80_next_83;
			m_history_12 = history_68_next_71;
			m_history_10 = history_56_next_59;
			m_history_8 = history_44_next_47;
			m_history_6 = history_32_next_35;
			m_history_4 = history_20_next_23;
			m_history_2 = history_8_next_11;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			
		};
		return __exception;
		
	};
	inline void set_sampler8(void * _value) {
		m_sampler_1.setbuffer(_value);
	};
	inline void set_sampler7(void * _value) {
		m_sampler_3.setbuffer(_value);
	};
	inline void set_sampler6(void * _value) {
		m_sampler_5.setbuffer(_value);
	};
	inline void set_sampler5(void * _value) {
		m_sampler_7.setbuffer(_value);
	};
	inline void set_sampler4(void * _value) {
		m_sampler_9.setbuffer(_value);
	};
	inline void set_sampler3(void * _value) {
		m_sampler_11.setbuffer(_value);
	};
	inline void set_sampler2(void * _value) {
		m_sampler_13.setbuffer(_value);
	};
	inline void set_sampler1(void * _value) {
		m_sampler_15.setbuffer(_value);
	};
	inline void set_playbackspeed(t_param _value) {
		m_playbackspeed_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_startpoint(t_param _value) {
		m_startpoint_42 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_record(t_param _value) {
		m_record_43 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_trigger(t_param _value) {
		m_trigger_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_wetdry(t_param _value) {
		m_wetdry_45 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_next(t_param _value) {
		m_next_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gain(t_param _value) {
		m_gain_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_initialise(t_param _value) {
		m_initialise_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_endpoint(t_param _value) {
		m_endpoint_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 3;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 17; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "audio in L", "audio in R" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_endpoint(value); break;
		case 1: self->set_gain(value); break;
		case 2: self->set_initialise(value); break;
		case 3: self->set_next(value); break;
		case 4: self->set_playbackspeed(value); break;
		case 5: self->set_record(value); break;
		case 6: self->set_sampler1(ref); break;
		case 7: self->set_sampler2(ref); break;
		case 8: self->set_sampler3(ref); break;
		case 9: self->set_sampler4(ref); break;
		case 10: self->set_sampler5(ref); break;
		case 11: self->set_sampler6(ref); break;
		case 12: self->set_sampler7(ref); break;
		case 13: self->set_sampler8(ref); break;
		case 14: self->set_startpoint(value); break;
		case 15: self->set_trigger(value); break;
		case 16: self->set_wetdry(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_endpoint_49; break;
		case 1: *value = self->m_gain_47; break;
		case 2: *value = self->m_initialise_48; break;
		case 3: *value = self->m_next_46; break;
		case 4: *value = self->m_playbackspeed_41; break;
		case 5: *value = self->m_record_43; break;
		
		
		
		
		
		
		
		
		case 14: *value = self->m_startpoint_42; break;
		case 15: *value = self->m_trigger_44; break;
		case 16: *value = self->m_wetdry_45; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(17 * sizeof(ParamInfo));
	self->__commonstate.numparams = 17;
	// initialize parameter 0 ("m_endpoint_49")
	pi = self->__commonstate.params + 0;
	pi->name = "endpoint";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_endpoint_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_gain_47")
	pi = self->__commonstate.params + 1;
	pi->name = "gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gain_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_initialise_48")
	pi = self->__commonstate.params + 2;
	pi->name = "initialise";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_initialise_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_next_46")
	pi = self->__commonstate.params + 3;
	pi->name = "next";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_next_46;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_playbackspeed_41")
	pi = self->__commonstate.params + 4;
	pi->name = "playbackspeed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_playbackspeed_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_record_43")
	pi = self->__commonstate.params + 5;
	pi->name = "record";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_record_43;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sampler_15")
	pi = self->__commonstate.params + 6;
	pi->name = "sampler1";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sampler_13")
	pi = self->__commonstate.params + 7;
	pi->name = "sampler2";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_sampler_11")
	pi = self->__commonstate.params + 8;
	pi->name = "sampler3";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sampler_9")
	pi = self->__commonstate.params + 9;
	pi->name = "sampler4";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sampler_7")
	pi = self->__commonstate.params + 10;
	pi->name = "sampler5";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_sampler_5")
	pi = self->__commonstate.params + 11;
	pi->name = "sampler6";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sampler_3")
	pi = self->__commonstate.params + 12;
	pi->name = "sampler7";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sampler_1")
	pi = self->__commonstate.params + 13;
	pi->name = "sampler8";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_startpoint_42")
	pi = self->__commonstate.params + 14;
	pi->name = "startpoint";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_startpoint_42;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_trigger_44")
	pi = self->__commonstate.params + 15;
	pi->name = "trigger";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_trigger_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_wetdry_45")
	pi = self->__commonstate.params + 16;
	pi->name = "wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_wetdry_45;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // main::
