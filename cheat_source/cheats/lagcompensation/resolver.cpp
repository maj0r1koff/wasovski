// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "animation_system.h"
#include "..\ragebot\aim.h"

void resolver::initialize(player_t* e, adjust_data* record, const float& goal_feet_yaw, const float& pitch)
{
	player = e;
	player_record = record;

	original_goal_feet_yaw = math::normalize_yaw(goal_feet_yaw);
	original_pitch = math::normalize_pitch(pitch);
}

void resolver::reset()
{
	player = nullptr;
	player_record = nullptr;

	side = false;
	fake = false;

	was_first_bruteforce = false;
	was_second_bruteforce = false;

	original_goal_feet_yaw = 0.0f;
	original_pitch = 0.0f;
}

void resolver::resolve_yaw()
{
	player_info_t player_info;

	if (!m_engine()->GetPlayerInfo(player->EntIndex(), &player_info))
		return;

#if RELEASE
	if (player_info.fakeplayer || !g_ctx.local()->is_alive() || player->m_iTeamNum() == g_ctx.local()->m_iTeamNum()) //-V807
#else
	if (!g_ctx.local()->is_alive() || player->m_iTeamNum() == g_ctx.local()->m_iTeamNum())
#endif
	{
		player_record->side = RESOLVER_ORIGINAL;
		return;
	}

	if (g_ctx.globals.missed_shots[player->EntIndex()] >= 2 || g_ctx.globals.missed_shots[player->EntIndex()] && aim::get().last_target[player->EntIndex()].record.type != LBY)
	{
		switch (last_side)
		{
		case RESOLVER_ORIGINAL:
			g_ctx.globals.missed_shots[player->EntIndex()] = 0;
			fake = true;
			break;
		case RESOLVER_ZERO:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_FIRST;

			was_first_bruteforce = false;
			was_second_bruteforce = false;
			return;
		case RESOLVER_1:
			player_record->type = BRUTEFORCE;
			player_record->side = was_second_bruteforce ? RESOLVER_ZERO : RESOLVER_2;

			was_first_bruteforce = true;
			return;
		case RESOLVER_2:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_3;

			was_second_bruteforce = false;
			return;
		case RESOLVER_3:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_4;

			was_second_bruteforce = false;
			return;
		case RESOLVER_4:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_5;

			was_second_bruteforce = false;
			return;
		case RESOLVER_5:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_6;

			was_second_bruteforce = false;
			return;
		case RESOLVER_6:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_7;

			was_second_bruteforce = false;
			return;
		case RESOLVER_7:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_8;

			was_second_bruteforce = false;
			return;
		case RESOLVER_8:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_9;

			was_second_bruteforce = false;
			return;
		case RESOLVER_9:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_10;

			was_second_bruteforce = false;
			return;
		case RESOLVER_10:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_11;

			was_second_bruteforce = true;
			return;
		case RESOLVER_11:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_12;

			was_second_bruteforce = false;
			return;
		case RESOLVER_12:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_13;

			was_second_bruteforce = false;
			return;
		case RESOLVER_13:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_14;

			was_second_bruteforce = false;
			return;
		case RESOLVER_14:
			player_record->type = BRUTEFORCE;
			player_record->side = was_first_bruteforce ? RESOLVER_ZERO : RESOLVER_1;

			was_second_bruteforce = true;
			return;
		case RESOLVER_LOW_FIRST:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_SECOND;
			return;
		case RESOLVER_LOW_SECOND:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_3;
			return;
		case RESOLVER_LOW_3:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_4;
			return;
		case RESOLVER_LOW_4:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_5;
			return;
		case RESOLVER_LOW_5:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_6;
			return;
		case RESOLVER_LOW_6:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_7;
			return;
		case RESOLVER_LOW_7:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_8;
			return;
		case RESOLVER_LOW_8:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_9;
			return;
		case RESOLVER_LOW_9:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_10;
			return;
		case RESOLVER_LOW_10:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_11;
			return;
		case RESOLVER_LOW_11:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_12;
			return;
		case RESOLVER_LOW_12:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_13;
			return;
		case RESOLVER_LOW_13:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_LOW_14;
			return;
		case RESOLVER_LOW_14:
			player_record->type = BRUTEFORCE;
			player_record->side = RESOLVER_1;
			return;
		}
	}

	auto animstate = player->get_animation_state();

	if (!animstate)
	{
		player_record->side = RESOLVER_ORIGINAL;
		return;
	}

	if (fabs(original_pitch) > 85.0f)
		fake = true;
	else if (!fake)
	{
		player_record->side = RESOLVER_ORIGINAL;
		return;
	}

	auto delta = math::normalize_yaw(player->m_angEyeAngles().y - original_goal_feet_yaw);
	auto valid_lby = true;

	if (animstate->m_velocity > 0.1f || fabs(animstate->flUpVelocity) > 100.f)
		valid_lby = animstate->m_flTimeSinceStartedMoving < 0.22f;

	if (fabs(delta) > 30.0f && valid_lby)
	{
		if (g_ctx.globals.missed_shots[player->EntIndex()])
			delta = -delta;

		if (delta > 30.0f)
		{
			player_record->type = LBY;
			player_record->side = RESOLVER_1;
		}
		else if (delta < -30.0f)
		{
			player_record->type = LBY;
			player_record->side = RESOLVER_2;
		}
	}
	else
	{
		auto trace = false;

		if (m_globals()->m_curtime - lock_side > 2.0f)
		{
			auto first_visible = util::visible(g_ctx.globals.eye_pos, player->hitbox_position_matrix(HITBOX_HEAD, player_record->matrixes_data.first), player, g_ctx.local());
			auto second_visible = util::visible(g_ctx.globals.eye_pos, player->hitbox_position_matrix(HITBOX_HEAD, player_record->matrixes_data.second), player, g_ctx.local());

			if (first_visible != second_visible)
			{
				trace = true;
				side = second_visible;
				lock_side = m_globals()->m_curtime;
			}
			else
			{
				auto first_position = g_ctx.globals.eye_pos.DistTo(player->hitbox_position_matrix(HITBOX_HEAD, player_record->matrixes_data.first));
				auto second_position = g_ctx.globals.eye_pos.DistTo(player->hitbox_position_matrix(HITBOX_HEAD, player_record->matrixes_data.second));

				if (fabs(first_position - second_position) > 1.0f)
					side = first_position > second_position;
			}
		}
		else
			trace = true;

		if (side)
		{
			player_record->type = trace ? TRACE: DIRECTIONAL;
			player_record->side = RESOLVER_1;
		}
		else
		{
			player_record->type = trace ? TRACE : DIRECTIONAL;
			player_record->side = RESOLVER_2;
		}
	}
}

float resolver::resolve_pitch()
{
	return original_pitch;
}