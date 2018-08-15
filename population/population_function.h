#pragma once
#include "common\\common.h"
#include "population.h"

class world_state;
namespace nations {
	struct nation;
}

namespace population {
	void init_rebel_faction_from_rebel_type(rebel_faction&, rebel_type&);
	pop& make_new_pop(world_state& ws);
	void init_population_state(world_state& ws);
	void init_pop_demographics(world_state& ws, pop& p, int32_t size);
	bool is_pop_accepted(world_state& ws, pop& p, nations::nation& n);
	pop* get_unassigned_soldier_in_province(world_state& ws, provinces::province_tag prov);
	void set_militancy_direct(pop &p, float v);
	void set_literacy_direct(pop &p, float v);
	void set_consciousness_direct(pop &p, float v);
	economy::money_qnty_type desired_needs_spending(world_state& ws, pop const& p);
	nations::nation* get_pop_owner(world_state const& ws, pop const& p);
	bool is_dominant_issue(world_state const& ws, pop_tag id, issues::option_tag opt);
	bool is_dominant_ideology(world_state const& ws, pop_tag id, ideologies::ideology_tag opt);
	void destroy_pop_movement(world_state& ws, pop_movement& m);
	void destroy_rebel_faction(world_state& ws, rebel_faction& r);
}
