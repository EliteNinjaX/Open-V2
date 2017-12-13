#pragma once

#include <stdint.h>
#include <vector>

#ifndef _DEBUG
#define CALL __vectorcall
#else
#define CALL
#endif

enum modifiers {
	modifiers_none = 0x0,
	modifiers_alt = 0x4,
	modifiers_ctrl = 0x2,
	modifiers_shift = 0x1,
	modifiers_ctrl_shift = 0x3,
	modifiers_ctrl_alt = 0x6,
	modifiers_alt_shift = 0x5,
	modifiers_all = 0x7
};

enum class virtual_key : uint8_t {
	NONE = 0x00,
	LBUTTON = 0x01,
	RBUTTON = 0x02,
	CANCEL = 0x03,
	MBUTTON = 0x04,
	XBUTTON_1 = 0x05,
	XBUTTON_2 = 0x06,
	BACK = 0x08,
	TAB = 0x09,
	CLEAR = 0x0C,
	RETURN = 0x0D,
	SHIFT = 0x10,
	CONTROL = 0x11,
	MENU = 0x12,
	PAUSE = 0x13,
	CAPITAL = 0x14,
	KANA = 0x15,
	JUNJA = 0x17,
	FINAL = 0x18,
	KANJI = 0x19,
	ESCAPE = 0x1B,
	CONVERT = 0x1C,
	NONCONVERT = 0x1D,
	ACCEPT = 0x1E,
	MODECHANGE = 0x1F,
	SPACE = 0x20,
	PRIOR = 0x21,
	NEXT = 0x22,
	END = 0x23,
	HOME = 0x24,
	LEFT = 0x25,
	UP = 0x26,
	RIGHT = 0x27,
	DOWN = 0x28,
	SELECT = 0x29,
	PRINT = 0x2A,
	EXECUTE = 0x2B,
	SNAPSHOT = 0x2C,
	INSERT = 0x2D,
	DELETE_KEY = 0x2E,
	HELP = 0x2F,
	NUM_0 = 0x30,
	NUM_1 = 0x31,
	NUM_2 = 0x32,
	NUM_3 = 0x33,
	NUM_4 = 0x34,
	NUM_5 = 0x35,
	NUM_6 = 0x36,
	NUM_7 = 0x37,
	NUM_8 = 0x38,
	NUM_9 = 0x39,
	A = 0x41,
	B = 0x42,
	C = 0x43,
	D = 0x44,
	E = 0x45,
	F = 0x46,
	G = 0x47,
	H = 0x48,
	I = 0x49,
	J = 0x4A,
	K = 0x4B,
	L = 0x4C,
	M = 0x4D,
	N = 0x4E,
	O = 0x4F,
	P = 0x50,
	Q = 0x51,
	R = 0x52,
	S = 0x53,
	T = 0x54,
	U = 0x55,
	V = 0x56,
	W = 0x57,
	X = 0x58,
	Y = 0x59,
	Z = 0x5A,
	LWIN = 0x5B,
	RWIN = 0x5C,
	APPS = 0x5D,
	SLEEP = 0x5F,
	NUMPAD0 = 0x60,
	NUMPAD1 = 0x61,
	NUMPAD2 = 0x62,
	NUMPAD3 = 0x63,
	NUMPAD4 = 0x64,
	NUMPAD5 = 0x65,
	NUMPAD6 = 0x66,
	NUMPAD7 = 0x67,
	NUMPAD8 = 0x68,
	NUMPAD9 = 0x69,
	MULTIPLY = 0x6A,
	ADD = 0x6B,
	SEPARATOR = 0x6C,
	SUBTRACT = 0x6D,
	DECIMAL = 0x6E,
	DIVIDE = 0x6F,
	F1 = 0x70,
	F2 = 0x71,
	F3 = 0x72,
	F4 = 0x73,
	F5 = 0x74,
	F6 = 0x75,
	F7 = 0x76,
	F8 = 0x77,
	F9 = 0x78,
	F10 = 0x79,
	F11 = 0x7A,
	F12 = 0x7B,
	F13 = 0x7C,
	F14 = 0x7D,
	F15 = 0x7E,
	F16 = 0x7F,
	F17 = 0x80,
	F18 = 0x81,
	F19 = 0x82,
	F20 = 0x83,
	F21 = 0x84,
	F22 = 0x85,
	F23 = 0x86,
	F24 = 0x87,
	NAVIGATION_VIEW = 0x88,
	NAVIGATION_MENU = 0x89,
	NAVIGATION_UP = 0x8A,
	NAVIGATION_DOWN = 0x8B,
	NAVIGATION_LEFT = 0x8C,
	NAVIGATION_RIGHT = 0x8D,
	NAVIGATION_ACCEPT = 0x8E,
	NAVIGATION_CANCEL = 0x8F,
	NUMLOCK = 0x90,
	SCROLL = 0x91,
	OEM_NEC_EQUAL = 0x92,
	LSHIFT = 0xA0,
	RSHIFT = 0xA1,
	LCONTROL = 0xA2,
	RCONTROL = 0xA3,
	LMENU = 0xA4,
	RMENU = 0xA5,
	SEMICOLON = 0xBA,
	PLUS = 0xBB,
	COMMA = 0xBC,
	MINUS = 0xBD,
	PERIOD = 0xBE,
	FORWARD_SLASH = 0xBF,
	TILDA = 0xC0,
	OPEN_BRACKET = 0xDB,
	BACK_SLASH = 0xDC,
	CLOSED_BRACKET = 0xDD,
	QUOTE = 0xDE
};


inline char ascii_to_lower(char in) {
	constexpr static char converted[256] = {
		//      0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F
		/*0*/'\x00','\x01','\x02','\x03','\x04','\x05','\x06','\x07','\x08','\x09','\x0A','\x0B','\x0C','\x0D','\x0E','\x0F',
		/*1*/'\x10','\x11','\x12','\x13','\x14','\x15','\x16','\x17','\x18','\x19','\x1A','\x1B','\x1C','\x1D','\x1E','\x1F',
		/*2*/  ' ' ,  '!' ,  '\"',  '#' ,  '$' ,  '%' ,  '&' ,  '\'',  '(' ,  ')' ,  '*' ,  '+' ,  ',' ,  '-' ,  '.' ,  '/' ,
		/*3*/  '0' ,  '1' ,  '2' ,  '3' ,  '4' ,  '5' ,  '6' ,  '7' ,  '8' ,  '9' ,  ':' ,  ';' ,  '<' ,  '=' ,  '>' ,  '?' ,
		/*4*/  '@' ,  'a' ,  'b' ,  'c' ,  'd' ,  'e' ,  'f' ,  'g' ,  'h' ,  'i' ,  'j' ,  'k' ,  'l' ,  'm' ,  'n' ,  'o' ,
		/*5*/  'p' ,  'q' ,  'r' ,  's' ,  't' ,  'u' ,  'v' ,  'w' ,  'x' ,  'y' ,  'z' ,  '[' ,  '\\',  ']' ,  '^' ,  '_' ,
		/*6*/  '`' ,  'a' ,  'b' ,  'c' ,  'd' ,  'e' ,  'f' ,  'g' ,  'h' ,  'i' ,  'j' ,  'k' ,  'l',   'm' ,  'n' ,  'o' ,
		/*7*/  'p' ,  'q' ,  'r' ,  's' ,  't' ,  'u' ,  'v' ,  'w' ,  'x' ,  'y' ,  'z' ,  '{' ,  '|',   '}' ,  '~' ,'\x7F',
		/*8*/'\x80','\x81','\x82','\x83','\x84','\x85','\x86','\x87','\x88','\x89','\x8A','\x8B','\x8C','\x8D','\x8E','\x8F',
		/*9*/'\x90','\x91','\x92','\x93','\x94','\x95','\x96','\x97','\x98','\x99','\x9A','\x9B','\x9C','\x9D','\x9E','\x9F',
		/*A*/'\xA0','\xA1','\xA2','\xA3','\xA4','\xA5','\xA6','\xA7','\xA8','\xA9','\xAA','\xAB','\xAC','\xAD','\xAE','\xAF',
		/*B*/'\xB0','\xB1','\xB2','\xB3','\xB4','\xB5','\xB6','\xB7','\xB8','\xB9','\xBA','\xBB','\xBC','\xBD','\xBE','\xBF',
		/*C*/'\xC0','\xC1','\xC2','\xC3','\xC4','\xC5','\xC6','\xC7','\xC8','\xC9','\xCA','\xCB','\xCC','\xCD','\xCE','\xCF',
		/*D*/'\xD0','\xD1','\xD2','\xD3','\xD4','\xD5','\xD6','\xD7','\xD8','\xD9','\xDA','\xDB','\xDC','\xDD','\xDE','\xDF',
		/*E*/'\xE0','\xE1','\xE2','\xE3','\xE4','\xE5','\xE6','\xE7','\xE8','\xE9','\xEA','\xEB','\xEC','\xED','\xEE','\xEF',
		/*F*/'\xF0','\xF1','\xF2','\xF3','\xF4','\xF5','\xF6','\xF7','\xF8','\xF9','\xFA','\xFB','\xFC','\xFD','\xFE','\xFF'
	};

	return converted[(uint8_t)in];
}

struct vector_backed_string_data {
	uint32_t offset;
	uint16_t length;
	uint16_t high_mask;
};

template<typename char_type>
struct vector_backed_string {
	union {
		vector_backed_string_data vbs;
		const char_type* ptr;
	} data;
	vector_backed_string() { data.vbs = vector_backed_string_data{0, 0, (uint16_t)(-1)}; };
	vector_backed_string(const char_type* c) { data.ptr = c; };
	vector_backed_string(const char_type* start, const char_type* end, std::vector<char_type>& vec) {
		data.vbs.offset = vec.size();
		data.vbs.length = (uint16_t)(end - start);
		data.vbs.high_mask = (uint16_t)(-1);
		vec.insert(vec.end(), start, end);
	};
	vector_backed_string(const std::basic_string<char_type>& str, std::vector<char_type>& vec) {
		data.vbs.offset = vec.size();
		data.vbs.length = (uint16_t)(str.length());
		data.vbs.high_mask = (uint16_t)(-1);
		vec.insert(vec.end(), str.begin(), str.end());
	};
	int32_t length() const {
		return data.vbs.high_mask == (uint16_t)-1 ? data.vbs.length : strlen(data.ptr);
	}
	const char_type* get_str(const std::vector<char_type>& vec) const {
		return data.vbs.high_mask == (uint16_t)-1 ? vec.data() + data.vbs.offset : data.ptr;
	}
	std::basic_string<char_type> get_string(const std::vector<char_type>& vec) const {
		return data.vbs.high_mask == (uint16_t)-1 ? std::basic_string<char_type>(vec.data() + data.vbs.offset, size_t(data.vbs.length)) : std::basic_string<char_type>(data.ptr);
	}
};

template<typename char_type>
struct vector_backed_string_less {
	const std::vector<char_type>& backing;
	vector_backed_string_less(const std::vector<char_type>& b) : backing(b) {};
	bool operator()(vector_backed_string<char_type> a, vector_backed_string<char_type> b) const {
		const auto a_len = a.length();
		const auto b_len = b.length();
		if (a_len < b_len)
			return true;
		else if (a_len > b_len)
			return false;
		else {
			const char_type* __restrict a_str = a.get_str(backing);
			const char_type* __restrict b_str = b.get_str(backing);
			for (int32_t i = a_len - 1; i >= 0; --i) {
				if (a_str[i] < b_str[i])
					return true;
				if (a_str[i] > b_str[i])
					return false;
			}
		}
		return false;
	}
};

struct vector_backed_string_less_ci {
	const std::vector<char>& backing;
	vector_backed_string_less_ci(const std::vector<char>& b) : backing(b) {};
	bool operator()(vector_backed_string<char> a, vector_backed_string<char> b) const {
		const auto a_len = a.length();
		const auto b_len = b.length();
		if (a_len < b_len)
			return true;
		else if (a_len > b_len)
			return false;
		else {
			const char* __restrict a_str = a.get_str(backing);
			const char* __restrict b_str = b.get_str(backing);
			for (int32_t i = a_len - 1; i >= 0; --i) {
				if (ascii_to_lower(a_str[i]) < ascii_to_lower(b_str[i]))
					return true;
				if (ascii_to_lower(a_str[i]) > ascii_to_lower(b_str[i]))
					return false;
			}
		}
		return false;
	}
};

template<typename char_type>
struct vector_backed_string_equality {
	const std::vector<char_type>& backing;
	vector_backed_string_equality(const std::vector<char_type>& b) : backing(b) {};
	bool operator()(vector_backed_string<char_type> a, vector_backed_string<char_type> b) const {
		const auto a_len = a.length();
		const auto b_len = b.length();
		if (a_len != b_len)
			return false;
		else {
			const auto a_str = a.get_str(backing);
			const auto b_str = b.get_str(backing);
			for (int32_t i = a_len - 1; i >= 0; --i) {
				if (a_str[i] != b_str[i])
					return false;
			}
		}
		return true;
	}
};

struct vector_backed_string_equality_ci {
	const std::vector<char>& backing;
	vector_backed_string_equality_ci(const std::vector<char>& b) : backing(b) {};
	bool operator()(vector_backed_string<char> a, vector_backed_string<char> b) const {
		const auto a_len = a.length();
		const auto b_len = b.length();
		if (a_len != b_len)
			return false;
		else {
			const auto a_str = a.get_str(backing);
			const auto b_str = b.get_str(backing);
			for (int32_t i = a_len - 1; i >= 0; --i) {
				if (ascii_to_lower(a_str[i]) != ascii_to_lower(b_str[i]))
					return false;
			}
		}
		return true;
	}
};