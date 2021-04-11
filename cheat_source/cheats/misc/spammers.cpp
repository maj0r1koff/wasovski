// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "spammers.h"

void spammers::clan_tag()
{
	auto apply = [](const char* tag) -> void
	{
		using Fn = int(__fastcall*)(const char*, const char*);
		static auto fn = reinterpret_cast<Fn>(util::FindSignature(crypt_str("engine.dll"), crypt_str("53 56 57 8B DA 8B F9 FF 15")));

		fn(tag, tag);
	};

	static auto removed = false;

	if (!g_cfg.misc.clantag_spammer && !removed)
	{
		removed = true;
		apply(crypt_str(""));
		return;
	}

	if (g_cfg.misc.clantag_spammer)
	{
		auto nci = m_engine()->GetNetChannelInfo();

		if (!nci)
			return;

		static auto time = -1;

		auto ticks = TIME_TO_TICKS(nci->GetAvgLatency(FLOW_OUTGOING)) + (float)m_globals()->m_tickcount; //-V807
		auto intervals = 0.3f / m_globals()->m_intervalpertick;
		// clantag speed
		auto main_time = (int)(ticks / intervals) % 20;

		if (main_time != time && !m_clientstate()->iChokedCommands)
		{
			auto tag = crypt_str("");

			switch (main_time)
			{
			case 0:
				tag = crypt_str("W "); //-V1037
				break;
			case 1:
				tag = crypt_str("W@ ");
				break;
			case 2:
				tag = crypt_str("W@s ");
				break;
			case 3:
				tag = crypt_str("W@s0 ");
				break;
			case 4:
				tag = crypt_str("W@s0v ");
				break;
			case 5:
				tag = crypt_str("W@s0v$ ");
				break;
			case 6:
				tag = crypt_str("W@s0v$k ");
				break;
			case 7:
				tag = crypt_str("W@s0vsk1 ");
				break;
			case 8:
				tag = crypt_str("WASOVSKI ");
				break;
			case 9:
				tag = crypt_str("wasovski ");
				break;
			case 10:
				tag = crypt_str("WASOVSKI ");
				break;
			case 11:
				tag = crypt_str("wasovski ");
				break;
			case 12:
				tag = crypt_str("W@s0vsk1 ");
				break;
			case 13:
				tag = crypt_str("W@s0v$k ");
				break;
			case 14:
				tag = crypt_str("W@s0v$ ");
				break;
			case 15:
				tag = crypt_str("W@s0v ");
				break;
			case 16:
				tag = crypt_str("W@s0 ");
				break;
			case 17:
				tag = crypt_str("W@s ");
				break;
			case 18:
				tag = crypt_str("W@ ");
				break;
			case 19:
				tag = crypt_str("W ");
				break;
			}

			apply(tag);
			time = main_time;
		}

		removed = false;
	}
}