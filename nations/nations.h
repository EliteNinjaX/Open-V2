#pragma once
#include "common\\common.h"
#include "common\\shared_tags.h"
#include "concurrency_tools\\concurrency_tools.hpp"
#include "economy\\economy.h"
#include "issues\\issues.h"

namespace modifiers {
	struct national_focus;
}

namespace nations {
	struct state_instance;

	struct region_state_pair {
		provinces::state_tag region_id;
		state_instance* state;

		bool operator<(region_state_pair other)  const noexcept { return region_id < other.region_id; }
		bool operator==(region_state_pair other) const noexcept { return region_id == other.region_id; }
	};

	struct influence {
		float investment_amount = 0.0f;

		country_tag target;

		uint8_t amount = 0ui8; // up to 100
		int8_t level = 2i8; // 0 to 5 (5 = in sphere, 2 = netural)

		bool operator<(influence const& other)  const noexcept { return target < other.target; }
		bool operator==(influence const& other) const noexcept { return target == other.target; }
	};

	struct relationship {
		country_tag tag;
		int16_t value = 0;

		bool operator<(relationship const& other)  const noexcept { return tag < other.tag; }
		bool operator==(relationship const& other) const noexcept { return tag == other.tag; }
	};

	struct truce {
		date_tag until;
		country_tag tag;

		bool operator<(truce const& other)  const noexcept { return tag < other.tag; }
		bool operator==(truce const& other) const noexcept { return tag == other.tag; }
	};

	struct timed_national_modifier {
		date_tag expiration;
		modifiers::national_modifier_tag mod;

		bool operator<(timed_national_modifier const& other)  const noexcept { return mod < other.mod; }
		bool operator==(timed_national_modifier const& other) const noexcept { return mod == other.mod; }
	};

	struct nation {
		nation* sphere_leader = nullptr;
		nation* overlord = nullptr;

		issues::rules current_rules;
		atomic_tag<date_tag> last_update;
		date_tag last_election;

		float plurality = 0.0f;
		float revanchism = 0.0f;
		float prestige = 0.0f;
		float infamy = 0.0f;
		float war_exhaustion = 0.0f;
		float blockade_fraction = 0.0f;
		float rebel_control_fraction = 0.0f;
		float political_interest_fraction = 0.0f;
		float social_interest_fraction = 0.0f;
		float crime_fraction = 0.0f; //fraction of provinces with active crime

		set_tag<provinces::province_tag> owned_provinces;
		set_tag<provinces::province_tag> controlled_provinces;
		set_tag<country_tag> sphere_members;
		set_tag<country_tag> vassals;
		set_tag<country_tag> allies;
		set_tag<country_tag> neighboring_nations;
		set_tag<cultures::culture_tag> accepted_cultures;
		set_tag<region_state_pair> member_states;
		set_tag<influence> gp_influence;
		set_tag<relationship> relations;
		set_tag<truce> truces;
		set_tag<state_tag> national_focus_locations;
		set_tag<variables::national_flag_tag> national_flags;
		multiset_tag<modifiers::national_modifier_tag> static_modifiers;
		set_tag<timed_national_modifier> timed_modifiers;
		array_tag<military::leader_tag> generals;
		array_tag<military::leader_tag> admirals;
		array_tag<military::army_tag> armies;
		array_tag<military::fleet_tag> fleets;
		array_tag<military::war_identifier> wars_involved_in;
		array_tag<population::rebel_faction_tag> active_rebel_factions;

		text_data::text_tag name;
		text_data::text_tag adjective;
		modifiers::national_modifier_tag national_value;
		modifiers::national_modifier_tag tech_school;

		graphics::texture_tag flag;

		graphics::color_rgb current_color;
		country_tag id;

		int16_t military_score = 0i16;
		int16_t industrial_score = 0i16;
		int16_t overall_rank = 0i16;
		int16_t prestige_rank = 0i16;
		int16_t military_rank = 0i16;
		int16_t industrial_rank = 0i16;

		uint16_t colonial_points = 0ui16;
		uint16_t num_ports = 0ui16; // number of ports connected to capital by land

		governments::party_tag ruling_party;
		provinces::province_tag current_capital;
		cultures::national_tag tag;

		cultures::culture_tag primary_culture;

		cultures::culture_tag dominant_culture;
		cultures::religion_tag dominant_religion;

		cultures::religion_tag national_religion;

		governments::government_tag current_government;

		uint8_t num_of_active_revolts;
		uint8_t flags = 0ui8;

		constexpr static uint8_t is_civilized = 0x01;
		constexpr static uint8_t is_substate = 0x02;
		constexpr static uint8_t is_mobilized = 0x04;
		constexpr static uint8_t is_not_ai_controlled = 0x08;
	};

	struct state_instance {
		economy::factory_instance factories[8] = {};
		std::pair<country_tag, int32_t> colonizers[4] = {};

		nation* owner = nullptr;
		modifiers::national_focus* owner_national_focus = nullptr;

		atomic_tag<date_tag> last_update;
		set_tag<country_tag> flashpoint_tension_focuses;
		float administrative_efficiency = 0.0f;
		float current_tension = 0.0f;

		cultures::culture_tag dominant_culture;

		cultures::national_tag crisis_tag;
		state_tag id;
		provinces::state_tag region_id;

		cultures::religion_tag dominant_religion;
		uint8_t flags = 0ui8;

		constexpr static uint8_t is_slave_state = 0x01;
		constexpr static uint8_t is_colonial = 0x02;
		constexpr static uint8_t is_protectorate = 0x02;
	};

	enum class crisis_type : int32_t {
		none,
		free_nation,
		colonial_crisis
	};

	class nations_state {
	public:
		array_tag<country_tag> nations_by_rank;

		stable_vector<nation, country_tag, 512, 16> nations;
		stable_vector<state_instance, state_tag, 512, 16> states;

		stable_2d_vector<governments::party_tag, country_tag, ideologies::ideology_tag, 512, 16> active_parties;
		stable_2d_vector<uint8_t, country_tag, ideologies::ideology_tag, 512, 16> upper_house;
		stable_2d_vector<uint64_t, country_tag, uint32_t, 512, 16> active_technologies;
		stable_2d_vector<issues::option_tag, country_tag, issues::issue_tag, 512, 16> active_issue_options;
		stable_2d_vector<modifiers::value_type, country_tag, uint32_t, 512, 16> national_modifiers;
		stable_2d_vector<economy::goods_qnty_type, country_tag, economy::goods_tag, 512, 16> national_stockpiles;

		stable_variable_vector_storage_mk_2<modifiers::national_modifier_tag, 4, 8192> static_modifier_arrays;
		stable_variable_vector_storage_mk_2<timed_national_modifier, 4, 8192> timed_modifier_arrays;

		stable_variable_vector_storage_mk_2<region_state_pair, 2, 8192> state_arrays;
		stable_variable_vector_storage_mk_2<influence, 2, 8192> influence_arrays;
		stable_variable_vector_storage_mk_2<country_tag, 4, 8192> nations_arrays;
		stable_variable_vector_storage_mk_2<state_tag, 4, 8192> state_tag_arrays;
		stable_variable_vector_storage_mk_2<relationship, 4, 8192> relations_arrays;
		stable_variable_vector_storage_mk_2<truce, 4, 8192> truce_arrays;

		stable_2d_vector<int32_t, state_tag, population::demo_tag, 512, 16> state_demographics;
		stable_2d_vector<int64_t, country_tag, population::demo_tag, 512, 16> nation_demographics;

		//crisis information
		int32_t crisis_temperature = 0;
		state_tag crisis_state;
		cultures::national_tag crisis_free_country;
		crisis_type current_crisis_type = crisis_type::none;
	};
}
