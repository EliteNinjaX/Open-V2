#pragma once
#include "common\\common.h"
#include "population_gui.h"
#include "provinces\\province_functions.hpp"
#include "nations\\nations_functions.hpp"
#include "population_function.h"
#include "gui\\gui.hpp"

namespace population {
	class pop_country_base : public ui::visible_region {
	public:
		nations::country_tag tag;

		void set_value(size_t, nations::country_tag t) {
			tag = t;
		}
	};

	class pop_country_open_button {
	public:
		nations::country_tag tag;

		template<typename W>
		void windowed_update(ui::simple_button<pop_country_open_button>&, W& w, world_state& ws);
		void button_function(ui::simple_button<pop_country_open_button>&, world_state&);
	};

	class pop_country_name {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_country_size {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_country_growth {
	public:
		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_country_growth>&, W& w, world_state& ws);
	};

	using pop_country_item = ui::gui_window <
		CT_STRING("poplistbutton"), ui::simple_button<pop_country_open_button>,
		CT_STRING("poplist_name"), ui::display_text<pop_country_name, 2>,
		CT_STRING("poplist_numpops"), ui::display_text<pop_country_size>,
		CT_STRING("growth_indicator"), ui::dynamic_icon<pop_country_growth>,
		pop_country_base
	>;

	class pop_state_base : public ui::visible_region {
	public:
		nations::state_tag tag;

		void set_value(size_t, nations::state_tag t) {
			tag = t;
		}
		template<typename W>
		void on_create(W& w, world_state&);
	};

	class pop_state_open_button {
	public:
		nations::state_tag tag;

		template<typename W>
		void windowed_update(ui::simple_button<pop_state_open_button>&, W& w, world_state& ws);
		void button_function(ui::simple_button<pop_state_open_button>&, world_state&);
	};

	class pop_state_name {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_state_focus_button {
	public:
		nations::state_tag tag;

		template<typename W>
		void windowed_update(ui::simple_button<pop_state_focus_button>&, W& w, world_state& ws);
		void button_function(ui::simple_button<pop_state_focus_button>&, world_state&);
	};

	class pop_colonial_state_button {
	public:
		template<typename W>
		void windowed_update(ui::simple_button<pop_colonial_state_button>&, W& w, world_state& ws);
	};

	class pop_state_size {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_state_expand_button {
	public:
		nations::state_tag tag;

		template<typename W>
		void windowed_update(ui::simple_button<pop_state_expand_button>&, W& w, world_state& ws);
		void button_function(ui::simple_button<pop_state_expand_button>&, world_state&);
		void on_create(ui::simple_button<pop_state_expand_button>&, world_state&);
	};

	class pop_state_growth {
	public:
		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_state_growth>&, W& w, world_state& ws);
	};

	using pop_state_item = ui::gui_window <
		CT_STRING("poplistbutton"), ui::simple_button<pop_state_open_button>,
		CT_STRING("poplist_name"), ui::display_text<pop_state_name, 6>,
		CT_STRING("colonial_state_icon"), ui::simple_button<pop_colonial_state_button>,
		CT_STRING("state_focus"), ui::simple_button<pop_state_focus_button>,
		CT_STRING("poplist_numpops"), ui::display_text<pop_state_size>,
		CT_STRING("expand"), ui::simple_button<pop_state_expand_button>,
		CT_STRING("growth_indicator"), ui::dynamic_icon<pop_state_growth>,
		pop_state_base
	>;

	class pop_province_base : public ui::visible_region {
	public:
		provinces::province_tag tag;

		void set_value(size_t, provinces::province_tag t) {
			tag = t;
		}
		template<typename W>
		void on_create(W& w, world_state&);
	};

	class pop_province_open_button {
	public:
		provinces::province_tag tag;

		template<typename W>
		void windowed_update(ui::simple_button<pop_province_open_button>&, W& w, world_state& ws);
		void button_function(ui::simple_button<pop_province_open_button>&, world_state&);
	};

	class pop_province_name {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_province_size {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_province_growth {
	public:
		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_province_growth>&, W& w, world_state& ws);
	};

	using pop_province_item = ui::gui_window <
		CT_STRING("poplistbutton"), ui::simple_button<pop_province_open_button>,
		CT_STRING("poplist_name"), ui::display_text<pop_province_name>,
		CT_STRING("poplist_numpops"), ui::display_text<pop_province_size>,
		CT_STRING("growth_indicator"), ui::dynamic_icon<pop_province_growth>,
		pop_province_base
	>;

	class pop_tree_view {
	public:
		static ui::window_tag element_tag(size_t level, ui::gui_static& gui_m);

		std::vector<nations::country_tag, concurrent_allocator<nations::country_tag>> base_list(world_state& ws);
		template<size_t level>
		std::vector<nations::state_tag, concurrent_allocator<nations::state_tag>> sub_list(nations::country_tag t, world_state& ws);
		template<size_t level>
		std::vector<provinces::province_tag, concurrent_allocator<provinces::province_tag>> sub_list(nations::state_tag t, world_state& ws);
	};

	class pop_list_item_base : public ui::visible_region {
	public:
		pop_tag tag;

		void set_value(pop_tag t) {
			tag = t;
		}
		template<typename W>
		void on_create(W& w, world_state&);
	};

	class pop_size {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_type_button {
	public:
		pop_type_tag type;

		template<typename W>
		void windowed_update(ui::simple_button<pop_type_button>&, W& w, world_state& ws);
		bool has_tooltip(world_state&) { return true; }
		void create_tooltip(world_state& ws, ui::tagged_gui_object tw);
	};

	class pop_producing_icon {
	public:
		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_producing_icon>& self, W& w, world_state& ws);
	};

	class pop_culture {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_religion {
	public:
		cultures::religion_tag religion;

		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_religion>&, W& w, world_state& ws);

		bool has_tooltip(world_state&) { return true; }
		void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	class pop_location {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_militancy {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_consciousness {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_ideology {
	public:
		template<typename window_type>
		void windowed_update(ui::piechart<pop_ideology>& pie, window_type&, world_state& ws);
	};

	class pop_issues {
	public:
		template<typename window_type>
		void windowed_update(ui::piechart<pop_issues>& pie, window_type&, world_state& ws);
	};

	class pop_unemployment_bar {
	public:
		template<typename window_type>
		void windowed_update(ui::progress_bar<pop_unemployment_bar>& bar, window_type&, world_state& ws);
	};

	class pop_cash {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class lifeneed_progress {
	public:
		template<typename window_type>
		void windowed_update(ui::progress_bar<lifeneed_progress>& bar, window_type&, world_state& ws);
	};
	class eveneed_progress {
	public:
		template<typename window_type>
		void windowed_update(ui::progress_bar<eveneed_progress>& bar, window_type&, world_state& ws);
	};
	class luxneed_progress {
	public:
		template<typename window_type>
		void windowed_update(ui::progress_bar<luxneed_progress>& bar, window_type&, world_state& ws);
	};

	class pops_unempl_overlay {
	public:
		float value = 0.0f;

		template<typename W>
		void windowed_update(ui::dynamic_icon<pops_unempl_overlay>&, W& w, world_state& ws);

		bool has_tooltip(world_state&) { return true; }
		void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	class lifeneed_progress_overlay {
	public:
		float value = 0.0f;

		template<typename W>
		void windowed_update(ui::dynamic_icon<lifeneed_progress_overlay>&, W& w, world_state& ws);

		bool has_tooltip(world_state&) { return true; }
		void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	class eveneed_progress_overlay {
	public:
		float value = 0.0f;

		template<typename W>
		void windowed_update(ui::dynamic_icon<eveneed_progress_overlay>&, W& w, world_state& ws);

		bool has_tooltip(world_state&) { return true; }
		void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};
	class luxneed_progress_overlay {
	public:
		float value = 0.0f;

		template<typename W>
		void windowed_update(ui::dynamic_icon<luxneed_progress_overlay>&, W& w, world_state& ws);

		bool has_tooltip(world_state&) { return true; }
		void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	class pop_literacy {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class pop_revolt {
	public:
		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_revolt>&, W& w, world_state& ws);

		//bool has_tooltip(world_state&) { return true; }
		//void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	class pop_movement_social {
	public:
		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_movement_social>&, W& w, world_state& ws);

		//bool has_tooltip(world_state&) { return true; }
		//void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	class pop_movement_political {
	public:
		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_movement_political>&, W& w, world_state& ws);

		//bool has_tooltip(world_state&) { return true; }
		//void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	class pop_movement_flag {
	public:
		template<typename W>
		void windowed_update(ui::masked_flag<pop_movement_flag>& self, W& w, world_state& ws);
		//bool has_tooltip(world_state&) { return true; }
		//void create_tooltip(ui::masked_flag<pop_movement_flag>& self, world_state& ws, ui::tagged_gui_object tw);
	};

	class pop_growth {
	public:
		template<typename W>
		void windowed_update(ui::dynamic_icon<pop_growth>&, W& w, world_state& ws);

		//bool has_tooltip(world_state&) { return true; }
		//void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	using pop_list_item = ui::gui_window <
		CT_STRING("pop_size"), ui::display_text<pop_size>,
		CT_STRING("pop_type"), ui::simple_button<pop_type_button>,
		CT_STRING("pop_producing_icon"), ui::dynamic_icon<pop_producing_icon>,
		CT_STRING("pop_nation"), ui::display_text<pop_culture>,
		CT_STRING("pop_religion"), ui::dynamic_icon<pop_religion>,
		CT_STRING("pop_location"), ui::display_text<pop_location>,
		CT_STRING("pop_mil"), ui::display_text<pop_militancy>,
		CT_STRING("pop_con"), ui::display_text<pop_consciousness>,
		CT_STRING("pop_ideology"), ui::piechart<pop_ideology>,
		CT_STRING("pop_issues"), ui::piechart<pop_issues>,
		CT_STRING("pop_unemployment_bar"), ui::progress_bar<pop_unemployment_bar>,
		CT_STRING("pop_cash"), ui::display_text<pop_cash>,
		CT_STRING("lifeneed_progress"), ui::progress_bar<lifeneed_progress>,
		CT_STRING("eveneed_progress"), ui::progress_bar<eveneed_progress>,
		CT_STRING("luxneed_progress"), ui::progress_bar<luxneed_progress>,
		CT_STRING("pops_unempl_overlay"), ui::dynamic_icon<pops_unempl_overlay>,
		CT_STRING("lifeneed_progress_overlay"), ui::dynamic_icon<lifeneed_progress_overlay>,
		CT_STRING("eveneed_progress_overlay"), ui::dynamic_icon<eveneed_progress_overlay>,
		CT_STRING("luxneed_progress_overlay"), ui::dynamic_icon<luxneed_progress_overlay>,
		CT_STRING("pop_revolt"), ui::dynamic_icon<pop_revolt>,
		CT_STRING("pop_movement_social"), ui::dynamic_icon<pop_movement_social>,
		CT_STRING("pop_movement_political"), ui::dynamic_icon<pop_movement_political>,
		CT_STRING("pop_movement_flag"), ui::masked_flag<pop_movement_flag>,
		CT_STRING("growth_indicator"), ui::dynamic_icon<pop_growth>,
		CT_STRING("pop_literacy"), ui::display_text<pop_literacy>,
		pop_list_item_base
	> ;

	class population_lb {
	public:
		template<typename lb_type>
		void populate_list(lb_type& lb, world_state& ws);
		ui::window_tag element_tag(ui::gui_static& m);
	};

	class pop_filter_button {
	public:
		pop_type_tag type;

		pop_filter_button(pop_type_tag t) : type(t) {}
		void button_function(ui::simple_button<pop_filter_button>&, world_state&);
		void update(ui::simple_button<pop_filter_button>&, world_state&);
		bool has_tooltip(world_state&) { return true; }
		void create_tooltip(world_state&, ui::tagged_gui_object tw);
	};

	class legend_item_base : public ui::visible_region {
	public:
		graphics::color_rgb color;
		text_data::text_tag legend_name;
		float percentage = 0;

		void set_value(std::tuple<graphics::color_rgb, text_data::text_tag, float> const& t) {
			color = std::get<0>(t);
			legend_name = std::get<1>(t);
			percentage = std::get<2>(t);
		}
	};

	class legend_icon {
	public:
		template<typename W>
		void windowed_update(ui::tinted_icon<legend_icon>&, W& w, world_state& ws);
	};

	class legend_label {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class legend_percentage {
	public:
		template<typename window_type>
		void windowed_update(window_type&, ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	using legend_item = ui::gui_window<
		CT_STRING("legend_color"), ui::tinted_icon<legend_icon>,
		CT_STRING("legend_title"), ui::display_text<legend_label>,
		CT_STRING("legend_value"), ui::display_text<legend_percentage, -20>,
		legend_item_base
	>;

	class workforce_title {
	public:
		void update(ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class workforce_chart {
	public:
		void update(ui::piechart<workforce_chart>& pie, world_state& ws);
	};

	class workforce_lb {
	public:
		template<typename lb_type>
		void populate_list(lb_type& lb, world_state& ws);
		ui::window_tag element_tag(ui::gui_static& m);
	};

	using workforce_details_window = ui::gui_window <
		CT_STRING("item_name"), ui::display_text<workforce_title, -22>,
		CT_STRING("chart"), ui::piechart<workforce_chart>,
		CT_STRING("member_names"), ui::discrete_listbox<workforce_lb, legend_item, std::tuple<graphics::color_rgb, text_data::text_tag, float>, 7>,
		ui::visible_region
	>;

	class religion_title {
	public:
		void update(ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class religion_chart {
	public:
		void update(ui::piechart<religion_chart>& pie, world_state& ws);
	};

	class religion_lb {
	public:
		template<typename lb_type>
		void populate_list(lb_type& lb, world_state& ws);
		ui::window_tag element_tag(ui::gui_static& m);
	};

	using religion_details_window = ui::gui_window <
		CT_STRING("item_name"), ui::display_text<religion_title, -22>,
		CT_STRING("chart"), ui::piechart<religion_chart>,
		CT_STRING("member_names"), ui::discrete_listbox<religion_lb, legend_item, std::tuple<graphics::color_rgb, text_data::text_tag, float>, 7>,
		ui::visible_region
	>;

	class culture_title {
	public:
		void update(ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class culture_chart {
	public:
		void update(ui::piechart<culture_chart>& pie, world_state& ws);
	};

	class culture_lb {
	public:
		template<typename lb_type>
		void populate_list(lb_type& lb, world_state& ws);
		ui::window_tag element_tag(ui::gui_static& m);
	};

	using culture_details_window = ui::gui_window <
		CT_STRING("item_name"), ui::display_text<culture_title, -22>,
		CT_STRING("chart"), ui::piechart<culture_chart>,
		CT_STRING("member_names"), ui::discrete_listbox<culture_lb, legend_item, std::tuple<graphics::color_rgb, text_data::text_tag, float>, 7>,
		ui::visible_region
	>;

	class ideology_title {
	public:
		void update(ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class ideology_chart {
	public:
		void update(ui::piechart<ideology_chart>& pie, world_state& ws);
	};

	class ideology_lb {
	public:
		template<typename lb_type>
		void populate_list(lb_type& lb, world_state& ws);
		ui::window_tag element_tag(ui::gui_static& m);
	};

	using ideology_details_window = ui::gui_window <
		CT_STRING("item_name"), ui::display_text<ideology_title, -22>,
		CT_STRING("chart"), ui::piechart<ideology_chart>,
		CT_STRING("member_names"), ui::discrete_listbox<ideology_lb, legend_item, std::tuple<graphics::color_rgb, text_data::text_tag, float>, 7>,
		ui::visible_region
	>;

	class issues_title {
	public:
		void update(ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class issues_chart {
	public:
		void update(ui::piechart<issues_chart>& pie, world_state& ws);
	};

	class issues_lb {
	public:
		template<typename lb_type>
		void populate_list(lb_type& lb, world_state& ws);
		ui::window_tag element_tag(ui::gui_static& m);
	};

	using issues_details_window = ui::gui_window <
		CT_STRING("item_name"), ui::display_text<issues_title, -22>,
		CT_STRING("chart"), ui::piechart<issues_chart>,
		CT_STRING("member_names"), ui::discrete_listbox<issues_lb, legend_item, std::tuple<graphics::color_rgb, text_data::text_tag, float>, 7>,
		ui::visible_region
	>;

	class electorate_title {
	public:
		void update(ui::tagged_gui_object, ui::text_box_line_manager&, ui::text_format&, world_state&);
	};

	class electorate_chart {
	public:
		void update(ui::piechart<electorate_chart>& pie, world_state& ws);
	};

	class electorate_lb {
	public:
		template<typename lb_type>
		void populate_list(lb_type& lb, world_state& ws);
		ui::window_tag element_tag(ui::gui_static& m);
	};

	using electorate_details_window = ui::gui_window <
		CT_STRING("item_name"), ui::display_text<electorate_title, -22>,
		CT_STRING("chart"), ui::piechart<electorate_chart>,
		CT_STRING("member_names"), ui::discrete_listbox<electorate_lb, legend_item, std::tuple<graphics::color_rgb, text_data::text_tag, float>, 7>,
		ui::visible_region
	>;

	class population_window_base : public ui::draggable_region {
	public:
		workforce_details_window workforce;
		culture_details_window cultures_w;
		ideology_details_window ideologies_w;
		issues_details_window issues_w;
		religion_details_window religions_w;
		electorate_details_window electorate_w;

		std::vector<ui::simple_button<pop_filter_button>> filter_buttons;

		population_window_base() {}
		population_window_base(population_window_base&&) = default;
		population_window_base(population_window_base& b) noexcept : population_window_base(std::move(b)) {}

		bool on_keydown(ui::gui_object_tag, world_state& ws, const ui::key_down& k) final override;
		template<typename W>
		void on_create(W& w, world_state&);
	};

	class popfilter_all_button {
	public:
		void button_function(ui::simple_button<popfilter_all_button>&, world_state&);
	};
	class popfilter_none_button {
	public:
		void button_function(ui::simple_button<popfilter_none_button>&, world_state&);
	};
	class sortby_size_button {
	public:
		void button_function(ui::simple_button<sortby_size_button>&, world_state&);
	};
	class sortby_type_button {
	public:
		void button_function(ui::simple_button<sortby_type_button>&, world_state&);
	};
	class sortby_nationality_button {
	public:
		void button_function(ui::simple_button<sortby_nationality_button>&, world_state&);
	};
	class sortby_religion_button {
	public:
		void button_function(ui::simple_button<sortby_religion_button>&, world_state&);
	};
	class sortby_location_button {
	public:
		void button_function(ui::simple_button<sortby_location_button>&, world_state&);
	};
	class sortby_mil_button {
	public:
		void button_function(ui::simple_button<sortby_mil_button>&, world_state&);
	};
	class sortby_con_button {
	public:
		void button_function(ui::simple_button<sortby_con_button>&, world_state&);
	};
	class sortby_ideology_button {
	public:
		void button_function(ui::simple_button<sortby_ideology_button>&, world_state&);
	};
	class sortby_issues_button {
	public:
		void button_function(ui::simple_button<sortby_issues_button>&, world_state&);
	};
	class sortby_unemployment_button {
	public:
		void button_function(ui::simple_button<sortby_unemployment_button>&, world_state&);
	};
	class sortby_cash_button {
	public:
		void button_function(ui::simple_button<sortby_cash_button>&, world_state&);
	};
	class sortby_subsistence_button {
	public:
		void button_function(ui::simple_button<sortby_subsistence_button>&, world_state&);
	};
	class sortby_eve_button {
	public:
		void button_function(ui::simple_button<sortby_eve_button>&, world_state&);
	};
	class sortby_luxury_button {
	public:
		void button_function(ui::simple_button<sortby_luxury_button>&, world_state&);
	};
	class sortby_revoltrisk_button {
	public:
		void button_function(ui::simple_button<sortby_revoltrisk_button>&, world_state&);
	};
	class sortby_change_button {
	public:
		void button_function(ui::simple_button<sortby_change_button>&, world_state&);
	};
	class sortby_literacy_button {
	public:
		void button_function(ui::simple_button<sortby_literacy_button>&, world_state&);
	};

	class close_button {
	public:
		void button_function(ui::simple_button<close_button>&, world_state&);
	};

	class dummy_scrollbar {
	public:
		void on_position(int32_t) const {}
	};

	class population_window_t : public ui::gui_window <
		CT_STRING("popfilter_ALL"), ui::simple_button<popfilter_all_button>,
		CT_STRING("popfilter_DESELECT_ALL"), ui::simple_button<popfilter_none_button>,
		CT_STRING("pop_province_list"),
		ui::tree_view<pop_tree_view,
		type_list<nations::country_tag, nations::state_tag, provinces::province_tag>,
		type_list<pop_country_item, pop_state_item, pop_province_item>>,
		CT_STRING("pop_list"), ui::discrete_listbox<population_lb, pop_list_item, pop_tag>,
		CT_STRING("external_scroll_slider"), ui::scrollbar<dummy_scrollbar>,
		CT_STRING("sortby_size_button"), ui::simple_button<sortby_size_button>,
		CT_STRING("sortby_type_button"), ui::simple_button<sortby_type_button>,
		CT_STRING("sortby_nationality_button"), ui::simple_button<sortby_nationality_button>,
		CT_STRING("sortby_religion_button"), ui::simple_button<sortby_religion_button>,
		CT_STRING("sortby_location_button"), ui::simple_button<sortby_location_button>,
		CT_STRING("sortby_mil_button"), ui::simple_button<sortby_mil_button>,
		CT_STRING("sortby_con_button"), ui::simple_button<sortby_con_button>,
		CT_STRING("sortby_ideology_button"), ui::simple_button<sortby_ideology_button>,
		CT_STRING("sortby_issues_button"), ui::simple_button<sortby_issues_button>,
		CT_STRING("sortby_unemployment_button"), ui::simple_button<sortby_unemployment_button>,
		CT_STRING("sortby_cash_button"), ui::simple_button<sortby_cash_button>,
		CT_STRING("sortby_subsistence_button"), ui::simple_button<sortby_subsistence_button>,
		CT_STRING("sortby_eve_button"), ui::simple_button<sortby_eve_button>,
		CT_STRING("sortby_luxury_button"), ui::simple_button<sortby_luxury_button>,
		CT_STRING("sortby_revoltrisk_button"), ui::simple_button<sortby_revoltrisk_button>,
		CT_STRING("sortby_change_button"), ui::simple_button<sortby_change_button>,
		CT_STRING("sortby_literacy_button"), ui::simple_button<sortby_literacy_button>,
		CT_STRING("close_button"), ui::simple_button<close_button>,
		population_window_base
		> {};

	template<typename W>
	void legend_icon::windowed_update(ui::tinted_icon<legend_icon>& self, W& w, world_state& ws) {
		self.set_color(ws.w.gui_m, float(w.color.r) / 255.0f, float(w.color.g) / 255.0f, float(w.color.b) / 255.0f);
	}

	template<typename window_type>
	void legend_label::windowed_update(window_type& win, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		ui::add_linear_text(ui::xy_pair{ 0,0 }, win.legend_name, fmt, ws.s.gui_m, ws.w.gui_m, box, lm);
		lm.finish_current_line();
	}

	template<typename window_type>
	void legend_percentage::windowed_update(window_type& win, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		char16_t formatted_value[64];
		put_value_in_buffer(formatted_value, display_type::percent, win.percentage);

		ui::text_chunk_to_instances(
			ws.s.gui_m,
			ws.w.gui_m,
			vector_backed_string<char16_t>(formatted_value),
			box,
			ui::xy_pair{ 0,0 },
			fmt,
			lm);

		lm.finish_current_line();
	}

	// returns: total pop

	template<typename tag_type, typename FUNC>
	void generic_for_each_pop(world_state& ws, tag_type tag, FUNC&& f) {
		if constexpr(std::is_same_v<tag_type, nations::country_tag>) {
			if(ws.w.nation_s.nations.is_valid_index(tag))
				nations::for_each_pop(ws, ws.w.nation_s.nations[tag], f);
		} else if constexpr(std::is_same_v<tag_type, nations::state_tag>) {
			if(ws.w.nation_s.states.is_valid_index(tag))
				nations::for_each_pop(ws, ws.w.nation_s.states[tag], f);
		} else if constexpr(std::is_same_v<tag_type, provinces::province_tag>) {
			if(is_valid_index(tag))
				provinces::for_each_pop(ws, ws.w.province_s.province_state_container[tag], f);
		}
	}

	template<typename category_type, typename tag_type>
	int64_t sum_filtered_demo_data(world_state& ws, int64_t* sums_out, tag_type tag) {
		int64_t total = 0;
		generic_for_each_pop(ws, tag, [sums_out, &ws, &total](population::pop& p) {
			auto pop_id = p.id;
			auto ptype = p.type;
			if(ws.w.population_s.pops.is_valid_index(pop_id) && is_valid_index(ptype) && ws.w.population_w.filtered_pop_types[ptype] != 0) {
				auto size = ws.w.population_s.pop_demographics.get(pop_id, population::total_population_tag);
				total += size;
				if constexpr(std::is_same_v<category_type, cultures::culture_tag>) {
					auto c = p.culture;
					if(is_valid_index(c))
						sums_out[to_index(c)] += size;
				} else if constexpr(std::is_same_v<category_type, cultures::religion_tag>) {
					auto c = p.religion;
					if(is_valid_index(c))
						sums_out[to_index(c)] += size;
				} else if constexpr(std::is_same_v<category_type, population::pop_type_tag>) {
					sums_out[to_index(ptype)] += size;
				} else if constexpr(std::is_same_v<category_type, ideologies::ideology_tag>) {
					for(uint32_t i = 0; i < ws.s.ideologies_m.ideologies_count; ++i) {
						sums_out[i] += ws.w.population_s.pop_demographics.get(pop_id, population::to_demo_tag(ws, ideologies::ideology_tag(static_cast<ideologies::ideology_tag::value_base_t>(i))));
					}
				} else if constexpr(std::is_same_v<category_type, issues::option_tag>) {
					for(uint32_t i = 0; i < ws.s.issues_m.tracked_options_count; ++i) {
						sums_out[i] += ws.w.population_s.pop_demographics.get(pop_id, population::to_demo_tag(ws, issues::option_tag(static_cast<issues::option_tag::value_base_t>(i))));
					}
				} else {
					std::abort(); // called with wrong category type
				}
			}
		});
		return total;
	}
	

	template<typename W>
	void pop_list_item_base::on_create(W& w, world_state&) {
		{
			auto& pie = w.template get<CT_STRING("pop_ideology")>();
			pie.associated_object->size.x *= 2;
			pie.associated_object->size.y *= 2;
		}
		{
			auto& pie = w.template get<CT_STRING("pop_issues")>();
			pie.associated_object->size.x *= 2;
			pie.associated_object->size.y *= 2;
		}
		{
			auto& bar = w.template get<CT_STRING("lifeneed_progress")>();
			bar.associated_object->position.x += 1;
		}
		{
			auto& bar = w.template get<CT_STRING("eveneed_progress")>();
			bar.associated_object->position.x += 3;
		}
	}

	template<typename W>
	void population_window_base::on_create(W& w, world_state& ws) {
		associated_object->size = ui::xy_pair{ 1017i16, 636i16 };
		ui::for_each_child(ws.w.gui_m, ui::tagged_gui_object{ *associated_object, ui::gui_object_tag() }, [](ui::tagged_gui_object obj) {
			obj.object.position += ui::xy_pair{ -3i16, 3i16 };
		});


		{
			auto wwin = ui::create_static_element(
				ws,
				std::get<ui::window_tag>(ws.s.gui_m.ui_definitions.name_to_element_map["distribution_window"]),
				ui::tagged_gui_object{ *associated_object, w.window_object },
				workforce);
			auto& pie = workforce.template get<CT_STRING("chart")>();
			pie.associated_object->size.x *= 2;
			pie.associated_object->size.y *= 2;
			workforce.associated_object->position = ui::xy_pair{ 252i16, 91i16 };
			workforce.associated_object->size = ui::xy_pair{ 255i16, 95i16 };
			ui::move_to_front(ws.w.gui_m, wwin);
		}

		{
			auto wwin = ui::create_static_element(
				ws,
				std::get<ui::window_tag>(ws.s.gui_m.ui_definitions.name_to_element_map["distribution_window"]),
				ui::tagged_gui_object{ *associated_object, w.window_object },
				cultures_w);
			auto& pie = cultures_w.template get<CT_STRING("chart")>();
			pie.associated_object->size.x *= 2;
			pie.associated_object->size.y *= 2;
			cultures_w.associated_object->position = ui::xy_pair{ int16_t(252 + 243), int16_t(91) };
			cultures_w.associated_object->size = ui::xy_pair{ 255i16, 95i16 };
			ui::move_to_front(ws.w.gui_m, wwin);
		}

		{
			auto wwin = ui::create_static_element(
				ws,
				std::get<ui::window_tag>(ws.s.gui_m.ui_definitions.name_to_element_map["distribution_window"]),
				ui::tagged_gui_object{ *associated_object, w.window_object },
				religions_w);
			auto& pie = religions_w.template get<CT_STRING("chart")>();
			pie.associated_object->size.x *= 2;
			pie.associated_object->size.y *= 2;
			religions_w.associated_object->position = ui::xy_pair{ int16_t(252 + 2 * 243), int16_t(91) };
			religions_w.associated_object->size = ui::xy_pair{ 255i16, 95i16 };
			ui::move_to_front(ws.w.gui_m, wwin);
		}

		{
			auto wwin = ui::create_static_element(
				ws,
				std::get<ui::window_tag>(ws.s.gui_m.ui_definitions.name_to_element_map["distribution_window"]),
				ui::tagged_gui_object{ *associated_object, w.window_object },
				ideologies_w);
			auto& pie = ideologies_w.template get<CT_STRING("chart")>();
			pie.associated_object->size.x *= 2;
			pie.associated_object->size.y *= 2;
			ideologies_w.associated_object->position = ui::xy_pair{ int16_t(252 + 0 * 243), int16_t(91 + 101) };
			ideologies_w.associated_object->size = ui::xy_pair{ 255i16, 95i16 };
			ui::move_to_front(ws.w.gui_m, wwin);
		}

		{
			auto wwin = ui::create_static_element(
				ws,
				std::get<ui::window_tag>(ws.s.gui_m.ui_definitions.name_to_element_map["distribution_window"]),
				ui::tagged_gui_object{ *associated_object, w.window_object },
				issues_w);
			auto& pie = issues_w.template get<CT_STRING("chart")>();
			pie.associated_object->size.x *= 2;
			pie.associated_object->size.y *= 2;
			issues_w.associated_object->position = ui::xy_pair{ int16_t(252 + 1 * 243), int16_t(91 + 101) };
			issues_w.associated_object->size = ui::xy_pair{ 255i16, 95i16 };
			ui::move_to_front(ws.w.gui_m, wwin);
		}

		{
			auto wwin = ui::create_static_element(
				ws,
				std::get<ui::window_tag>(ws.s.gui_m.ui_definitions.name_to_element_map["distribution_window"]),
				ui::tagged_gui_object{ *associated_object, w.window_object },
				electorate_w);
			auto& pie = electorate_w.template get<CT_STRING("chart")>();
			pie.associated_object->size.x *= 2;
			pie.associated_object->size.y *= 2;
			electorate_w.associated_object->position = ui::xy_pair{ int16_t(252 + 2 * 243), int16_t(91 + 101) };
			electorate_w.associated_object->size = ui::xy_pair{ 255i16, 95i16 };
			ui::move_to_front(ws.w.gui_m, wwin);
		}

		for(uint32_t i = 0; i < ws.s.population_m.count_poptypes; ++i) {
			filter_buttons.emplace_back(pop_type_tag(static_cast<pop_type_tag::value_base_t>(i)));

			auto fb = ui::create_static_element(
				ws,
				std::get<ui::button_tag>(ws.s.gui_m.ui_definitions.name_to_element_map["pop_filter_button"]),
				ui::tagged_gui_object{ *associated_object, w.window_object },
				filter_buttons.back());
			fb.object.position = ui::xy_pair{ int16_t(284 + 32 * i), int16_t(24) };
			ui::move_to_front(ws.w.gui_m, fb);
		}


		auto& close_button = w.template get<CT_STRING("close_button")>();
		close_button.associated_object->position = ui::xy_pair{ -31i16, -1i16 };

		auto& sb = w.template get<CT_STRING("external_scroll_slider")>();
		ui::hide(*sb.associated_object);

		{
			auto& b = w.template get<CT_STRING("sortby_mil_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_con_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_issues_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_unemployment_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_cash_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_subsistence_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_eve_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_luxury_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_revoltrisk_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_change_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_literacy_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}
		{
			auto& b = w.template get<CT_STRING("sortby_ideology_button")>();
			b.associated_object->position += ui::xy_pair{ 0i16, -1i16 };
			ui::clear_children(ws.w.gui_m, ui::tagged_gui_object{ *b.associated_object, ui::gui_object_tag(0) });
		}

		ui::hide(*associated_object);
	}

	template<typename lb_type>
	void population_lb::populate_list(lb_type& lb, world_state& ws) {
		boost::container::small_vector<pop_tag, 64, concurrent_allocator<pop_tag>> data;

		if(ws.w.population_w.display_type == population_display::nation) {
			generic_for_each_pop(ws, ws.w.population_w.population_for_nation, [&ws, &data](population::pop& p) {
				auto id = p.id;
				if(ws.w.population_s.pops.is_valid_index(id)) {
					auto type = ws.w.population_s.pops[id].type;
					if(is_valid_index(type) && ws.w.population_w.filtered_pop_types[type] != 0)
						data.push_back(id);
				}
			});
		} else if(ws.w.population_w.display_type == population_display::state) {
			generic_for_each_pop(ws, ws.w.population_w.population_for_state, [&ws, &data](population::pop& p) {
				auto id = p.id;
				if(ws.w.population_s.pops.is_valid_index(id)) {
					auto type = ws.w.population_s.pops[id].type;
					if(is_valid_index(type) && ws.w.population_w.filtered_pop_types[type] != 0)
						data.push_back(id);
				}
			});
		} else if(ws.w.population_w.display_type == population_display::province) {
			generic_for_each_pop(ws, ws.w.population_w.population_for_province, [&ws, &data](population::pop& p) {
				auto id = p.id;
				if(ws.w.population_s.pops.is_valid_index(id)) {
					auto type = ws.w.population_s.pops[id].type;
					if(is_valid_index(type) && ws.w.population_w.filtered_pop_types[type] != 0)
						data.push_back(id);
				}
			});
		}

		//do sorting
		switch(ws.w.population_w.sort_type) {
			case population_sort::none: break;
			case population_sort::size:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					return ws.w.population_s.pop_demographics.get(a, total_population_tag) > ws.w.population_s.pop_demographics.get(b, total_population_tag);
				});
				break;
			case population_sort::type:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					return ws.w.population_s.pops[a].type < ws.w.population_s.pops[b].type;
				});
				break;
			case population_sort::culture:
			{
				vector_backed_string_lex_less<char16_t> lss(ws.s.gui_m.text_data_sequences.text_data);
				std::sort(data.begin(), data.end(), [&ws, &lss](pop_tag a, pop_tag b) {
					auto a_culture = ws.w.population_s.pops[a].culture;
					auto b_culture = ws.w.population_s.pops[b].culture;
					return lss(
						text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences,
							is_valid_index(a_culture) ? ws.s.culture_m.culture_container[a_culture].name : text_data::text_tag()),
						text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences,
							is_valid_index(b_culture) ? ws.s.culture_m.culture_container[b_culture].name : text_data::text_tag()));
				});
			}
				break;
			case population_sort::religion:
			{
				vector_backed_string_lex_less<char16_t> lss(ws.s.gui_m.text_data_sequences.text_data);
				std::sort(data.begin(), data.end(), [&ws, &lss](pop_tag a, pop_tag b) {
					auto a_rel = ws.w.population_s.pops[a].religion;
					auto b_rel = ws.w.population_s.pops[b].religion;
					return lss(
						text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences,
							is_valid_index(a_rel) ? ws.s.culture_m.religions[a_rel].name : text_data::text_tag()),
						text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences,
							is_valid_index(b_rel) ? ws.s.culture_m.religions[b_rel].name : text_data::text_tag()));
				});
			}
				break;
			case population_sort::location:
			{
				vector_backed_string_lex_less<char16_t> lss(ws.s.gui_m.text_data_sequences.text_data);
				std::sort(data.begin(), data.end(), [&ws, &lss](pop_tag a, pop_tag b) {
					auto a_loc = ws.w.population_s.pops[a].location;
					auto b_loc = ws.w.population_s.pops[b].location;
					return lss(
						text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences,
							is_valid_index(a_loc) ? ws.w.province_s.province_state_container[a_loc].name : text_data::text_tag()),
						text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences,
							is_valid_index(b_loc) ? ws.w.province_s.province_state_container[b_loc].name : text_data::text_tag()));
				});
			}
				break;
			case population_sort::militancy:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					return ws.w.population_s.pops[a].militancy < ws.w.population_s.pops[b].militancy;
				});
				break;
			case population_sort::consciousness:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					return ws.w.population_s.pops[a].consciousness < ws.w.population_s.pops[b].consciousness;
				});
				break;
			case population_sort::ideoology: break;
			case population_sort::issues: break;
			case population_sort::unemployment:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					auto a_size = float(std::max(1, ws.w.population_s.pop_demographics.get(a, total_population_tag)));
					auto b_size = float(std::max(1, ws.w.population_s.pop_demographics.get(b, total_population_tag)));
					return float(ws.w.population_s.pop_demographics.get(a, total_employment_tag)) / a_size <
						float(ws.w.population_s.pop_demographics.get(b, total_employment_tag)) / b_size;
				});
				break;
			case population_sort::cash:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					return ws.w.population_s.pops[a].money < ws.w.population_s.pops[b].money;
				});
				break;
			case population_sort::life_needs: // fall through
			case population_sort::everyday_needs: // fall through
			case population_sort::luxury_needs:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					return ws.w.population_s.pops[a].needs_satisfaction < ws.w.population_s.pops[b].needs_satisfaction;
				});
				break;
			case population_sort::revolt_risk: break;
			case population_sort::size_change:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					return total_size_change(ws.w.population_s.pops[a]) < total_size_change(ws.w.population_s.pops[b]);
				});
				break;
			case population_sort::literacy:
				std::sort(data.begin(), data.end(), [&ws](pop_tag a, pop_tag b) {
					return ws.w.population_s.pops[a].literacy < ws.w.population_s.pops[b].literacy;
				});
				break;
		}

		lb.update_list(data.begin().get_ptr(), data.end().get_ptr());
	}

	template<typename lb_type>
	void workforce_lb::populate_list(lb_type& lb, world_state & ws) {
		boost::container::small_vector<std::tuple<graphics::color_rgb, text_data::text_tag, float>, 32> data;

		int64_t* sums_out = (int64_t*)_alloca(sizeof(int64_t) * ws.s.population_m.count_poptypes);
		int64_t total_size = 0;
		std::fill_n(sums_out, ws.s.population_m.count_poptypes, 0);
		
		if(ws.w.population_w.display_type == population_display::nation) {
			total_size = sum_filtered_demo_data<population::pop_type_tag>(ws, sums_out, ws.w.population_w.population_for_nation);
		} else if(ws.w.population_w.display_type == population_display::state) {
			total_size = sum_filtered_demo_data<population::pop_type_tag>(ws, sums_out, ws.w.population_w.population_for_state);
		} else if(ws.w.population_w.display_type == population_display::province) {
			total_size = sum_filtered_demo_data<population::pop_type_tag>(ws, sums_out, ws.w.population_w.population_for_province);
		}

		if(total_size == 0) {
			lb.new_list(nullptr, nullptr);
			return;
		}

		for(uint32_t i = 0; i < ws.s.population_m.count_poptypes; ++i) {
			if(sums_out[i] != 0)
				data.emplace_back(
					ws.s.population_m.pop_types[population::pop_type_tag(static_cast<population::pop_type_tag::value_base_t>(i))].color,
					ws.s.population_m.pop_types[population::pop_type_tag(static_cast<population::pop_type_tag::value_base_t>(i))].name,
					float(sums_out[i]) / float(total_size));
		}

		lb.new_list(data.begin().get_ptr(), data.end().get_ptr());
	}

	template<typename lb_type>
	void religion_lb::populate_list(lb_type& lb, world_state & ws) {
		boost::container::small_vector<std::tuple<graphics::color_rgb, text_data::text_tag, float>, 32> data;

		int64_t* sums_out = (int64_t*)_alloca(sizeof(int64_t) * ws.s.culture_m.count_religions);
		int64_t total_size = 0;
		std::fill_n(sums_out, ws.s.culture_m.count_religions, 0);

		if(ws.w.population_w.display_type == population_display::nation) {
			total_size = sum_filtered_demo_data<cultures::religion_tag>(ws, sums_out, ws.w.population_w.population_for_nation);
		} else if(ws.w.population_w.display_type == population_display::state) {
			total_size = sum_filtered_demo_data<cultures::religion_tag>(ws, sums_out, ws.w.population_w.population_for_state);
		} else if(ws.w.population_w.display_type == population_display::province) {
			total_size = sum_filtered_demo_data<cultures::religion_tag>(ws, sums_out, ws.w.population_w.population_for_province);
		}

		if(total_size == 0) {
			lb.new_list(nullptr, nullptr);
			return;
		}

		for(uint32_t i = 0; i < ws.s.culture_m.count_religions; ++i) {
			if(sums_out[i] != 0)
				data.emplace_back(
					ws.s.culture_m.religions[cultures::religion_tag(static_cast<cultures::religion_tag::value_base_t>(i))].color,
					ws.s.culture_m.religions[cultures::religion_tag(static_cast<cultures::religion_tag::value_base_t>(i))].name,
					float(sums_out[i]) / float(total_size));
		}

		lb.new_list(data.begin().get_ptr(), data.end().get_ptr());
	}

	template<typename lb_type>
	void ideology_lb::populate_list(lb_type& lb, world_state & ws) {
		boost::container::small_vector<std::tuple<graphics::color_rgb, text_data::text_tag, float>, 32> data;

		int64_t* sums_out = (int64_t*)_alloca(sizeof(int64_t) * ws.s.ideologies_m.ideologies_count);
		int64_t total_size = 0;
		std::fill_n(sums_out, ws.s.ideologies_m.ideologies_count, 0);

		if(ws.w.population_w.display_type == population_display::nation) {
			total_size = sum_filtered_demo_data<ideologies::ideology_tag>(ws, sums_out, ws.w.population_w.population_for_nation);
		} else if(ws.w.population_w.display_type == population_display::state) {
			total_size = sum_filtered_demo_data<ideologies::ideology_tag>(ws, sums_out, ws.w.population_w.population_for_state);
		} else if(ws.w.population_w.display_type == population_display::province) {
			total_size = sum_filtered_demo_data<ideologies::ideology_tag>(ws, sums_out, ws.w.population_w.population_for_province);
		}

		if(total_size == 0) {
			lb.new_list(nullptr, nullptr);
			return;
		}

		for(uint32_t i = 0; i < ws.s.ideologies_m.ideologies_count; ++i) {
			if(sums_out[i] != 0)
				data.emplace_back(
					ws.s.ideologies_m.ideology_container[ideologies::ideology_tag(static_cast<ideologies::ideology_tag::value_base_t>(i))].color,
					ws.s.ideologies_m.ideology_container[ideologies::ideology_tag(static_cast<ideologies::ideology_tag::value_base_t>(i))].name,
					float(sums_out[i]) / float(total_size));
		}

		lb.new_list(data.begin().get_ptr(), data.end().get_ptr());
	}

	template<typename lb_type>
	void electorate_lb::populate_list(lb_type&, world_state&) {
	}

	template <typename lb_type>
	void culture_lb::populate_list(lb_type& lb, world_state & ws) {
		boost::container::small_vector<std::tuple<graphics::color_rgb, text_data::text_tag, float>, 32> data;

		std::vector<int64_t, concurrent_allocator<int64_t>> sums_out(ws.s.culture_m.count_cultures);
		int64_t total_size = 0;

		if(ws.w.population_w.display_type == population_display::nation) {
			total_size = sum_filtered_demo_data<cultures::culture_tag>(ws, sums_out.data(), ws.w.population_w.population_for_nation);
		} else if(ws.w.population_w.display_type == population_display::state) {
			total_size = sum_filtered_demo_data<cultures::culture_tag>(ws, sums_out.data(), ws.w.population_w.population_for_state);
		} else if(ws.w.population_w.display_type == population_display::province) {
			total_size = sum_filtered_demo_data<cultures::culture_tag>(ws, sums_out.data(), ws.w.population_w.population_for_province);
		}

		if(total_size == 0) {
			lb.new_list(nullptr, nullptr);
			return;
		}

		for(uint32_t i = 0; i < ws.s.culture_m.count_cultures; ++i) {
			if(sums_out[i] != 0)
				data.emplace_back(
					ws.s.culture_m.culture_container[cultures::culture_tag(static_cast<cultures::culture_tag::value_base_t>(i))].color,
					ws.s.culture_m.culture_container[cultures::culture_tag(static_cast<cultures::culture_tag::value_base_t>(i))].name,
					float(sums_out[i]) / float(total_size));
		}

		lb.new_list(data.begin().get_ptr(), data.end().get_ptr());
	}

	template <typename lb_type>
	void issues_lb::populate_list(lb_type& lb, world_state & ws) {
		boost::container::small_vector<std::tuple<graphics::color_rgb, text_data::text_tag, float>, 32> data;

		std::vector<int64_t, concurrent_allocator<int64_t>> sums_out(ws.s.issues_m.tracked_options_count);
		int64_t total_size = 0;

		if(ws.w.population_w.display_type == population_display::nation) {
			total_size = sum_filtered_demo_data<issues::option_tag>(ws, sums_out.data(), ws.w.population_w.population_for_nation);
		} else if(ws.w.population_w.display_type == population_display::state) {
			total_size = sum_filtered_demo_data<issues::option_tag>(ws, sums_out.data(), ws.w.population_w.population_for_state);
		} else if(ws.w.population_w.display_type == population_display::province) {
			total_size = sum_filtered_demo_data<issues::option_tag>(ws, sums_out.data(), ws.w.population_w.population_for_province);
		}

		if(total_size == 0) {
			lb.new_list(nullptr, nullptr);
			return;
		}

		for(uint32_t i = 0; i < ws.s.issues_m.tracked_options_count; ++i) {
			if(sums_out[i] != 0)
				data.emplace_back(
					ws.s.issues_m.options[issues::option_tag(static_cast<issues::option_tag::value_base_t>(i))].color,
					ws.s.issues_m.options[issues::option_tag(static_cast<issues::option_tag::value_base_t>(i))].name,
					float(sums_out[i]) / float(total_size));
		}

		lb.new_list(data.begin().get_ptr(), data.end().get_ptr());
	}

	template<typename window_type>
	void pop_size::windowed_update(window_type& w, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		char16_t local_buf[32];
		put_value_in_buffer(local_buf, display_type::exact_integer, int32_t(ws.w.population_s.pop_demographics.get(w.tag, total_population_tag)));

		ui::text_chunk_to_instances(
			ws.s.gui_m,
			ws.w.gui_m,
			vector_backed_string<char16_t>(local_buf),
			box,
			ui::xy_pair{ 0,0 },
			fmt,
			lm);
		lm.finish_current_line();
	}

	template<typename window_type>
	void pop_culture::windowed_update(window_type& w, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		cultures::culture_tag c = ws.w.population_s.pops[w.tag].culture;
		if(is_valid_index(c))
			ui::add_linear_text(ui::xy_pair{ 0, 0 }, ws.s.culture_m.culture_container[c].name, fmt, ws.s.gui_m, ws.w.gui_m, box, lm);
		lm.finish_current_line();
	}

	template<typename window_type>
	void pop_location::windowed_update(window_type& w, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		provinces::province_tag p = ws.w.population_s.pops[w.tag].location;
		if(is_valid_index(p))
			ui::add_linear_text(ui::xy_pair{ 0, 0 }, ws.w.province_s.province_state_container[p].name, fmt, ws.s.gui_m, ws.w.gui_m, box, lm);
		lm.finish_current_line();
	}

	template<typename window_type>
	void pop_militancy::windowed_update(window_type& w, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		float mil = population::get_militancy_direct(ws.w.population_s.pops[w.tag]);

		char16_t local_buf[32];
		put_value_in_buffer(local_buf, display_type::fp_two_places, mil);

		ui::text_chunk_to_instances(
			ws.s.gui_m,
			ws.w.gui_m,
			vector_backed_string<char16_t>(local_buf),
			box,
			ui::xy_pair{ 0,0 },
			fmt,
			lm);

		lm.finish_current_line();
	}

	template<typename window_type>
	void pop_consciousness::windowed_update(window_type& w, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		float mil = population::get_consciousness_direct(ws.w.population_s.pops[w.tag]);

		char16_t local_buf[32];
		put_value_in_buffer(local_buf, display_type::fp_two_places, mil);

		ui::text_chunk_to_instances(
			ws.s.gui_m,
			ws.w.gui_m,
			vector_backed_string<char16_t>(local_buf),
			box,
			ui::xy_pair{ 0,0 },
			fmt,
			lm);

		lm.finish_current_line();
	}

	template<typename window_type>
	void pop_literacy::windowed_update(window_type& w, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		float mil = population::get_literacy_direct(ws.w.population_s.pops[w.tag]);

		char16_t local_buf[32];
		put_value_in_buffer(local_buf, display_type::percent, mil);

		ui::text_chunk_to_instances(
			ws.s.gui_m,
			ws.w.gui_m,
			vector_backed_string<char16_t>(local_buf),
			box,
			ui::xy_pair{ 0,0 },
			fmt,
			lm);

		lm.finish_current_line();
	}

	template<typename window_type>
	void pop_cash::windowed_update(window_type& w, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		float money = ws.w.population_s.pops[w.tag].money;

		char16_t local_buf[32];
		put_value_in_buffer(local_buf, display_type::fp_two_places, money);

		ui::text_chunk_to_instances(
			ws.s.gui_m,
			ws.w.gui_m,
			vector_backed_string<char16_t>(local_buf),
			box,
			ui::xy_pair{ 0,0 },
			fmt,
			lm);

		lm.finish_current_line();
	}

	template<typename window_type>
	void pop_ideology::windowed_update(ui::piechart<pop_ideology>& pie, window_type& w, world_state& ws) {
		int32_t* demo = ws.w.population_s.pop_demographics.get_row(w.tag);
		int32_t* ideologies_values = demo + to_index(to_demo_tag(ws, ideologies::ideology_tag(0)));

		float size = float(demo[to_index(total_population_tag)]);
		if(size != 0.0f) {
			for(uint32_t i = 0; i < ws.s.ideologies_m.ideologies_count; ++i) {
				if(ideologies_values[i] != 0)
					pie.add_entry(
						ws.w.gui_m,
						text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences, ws.s.ideologies_m.ideology_container[ideologies::ideology_tag(static_cast<ideologies::ideology_tag::value_base_t>(i))].name),
						float(ideologies_values[i]) / size,
						ws.s.ideologies_m.ideology_container[ideologies::ideology_tag(static_cast<ideologies::ideology_tag::value_base_t>(i))].color);
			}
		}
	}

	template<typename window_type>
	void pop_issues::windowed_update(ui::piechart<pop_issues>& pie, window_type& w, world_state& ws) {
		int32_t* demo = ws.w.population_s.pop_demographics.get_row(w.tag);
		int32_t* issues_values = demo + to_index(to_demo_tag(ws, issues::option_tag(0)));

		float size = float(demo[to_index(total_population_tag)]);
		if(size != 0.0f) {
			for(uint32_t i = 0; i < ws.s.issues_m.tracked_options_count; ++i) {
				if(issues_values[i] != 0)
					pie.add_entry(
						ws.w.gui_m,
						text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences, ws.s.issues_m.options[issues::option_tag(static_cast<issues::option_tag::value_base_t>(i))].name),
						float(issues_values[i]) / size,
						ws.s.issues_m.options[issues::option_tag(static_cast<issues::option_tag::value_base_t>(i))].color);
			}
		}
	}

	template<typename W>
	void pop_type_button::windowed_update(ui::simple_button<pop_type_button>& b, W& w, world_state& ws) {
		auto& pop = ws.w.population_s.pops[w.tag];
		type = pop.type;
		if(is_valid_index(type)) 
			b.set_frame(ws.w.gui_m, ws.s.population_m.pop_types[type].sprite - 1ui32);
	}

	template<typename W>
	void pop_producing_icon::windowed_update(ui::dynamic_icon<pop_producing_icon>& self, W& w, world_state& ws) {
		ui::hide(*self.associated_object);
	}

	template<typename W>
	void pop_religion::windowed_update(ui::dynamic_icon<pop_religion>& ico, W& w, world_state& ws) {
		religion = ws.w.population_s.pops[w.tag].religion;
		if(is_valid_index(religion))
			ico.set_frame(ws.w.gui_m, uint32_t(ws.s.culture_m.religions[religion].icon) - 1ui32);
	}

	template<typename window_type>
	void pop_unemployment_bar::windowed_update(ui::progress_bar<pop_unemployment_bar>& bar, window_type& w, world_state& ws) {
		float size = float(ws.w.population_s.pop_demographics.get(w.tag, total_population_tag));
		float employed = float(ws.w.population_s.pop_demographics.get(w.tag, total_employment_tag));

		if(size != 0.0f) 
			bar.set_fraction(1.0f - employed / size);
		else 
			bar.set_fraction(0.0f);
	}

	template<typename W>
	void pops_unempl_overlay::windowed_update(ui::dynamic_icon<pops_unempl_overlay>&, W& w, world_state& ws) {
		float size = float(ws.w.population_s.pop_demographics.get(w.tag, total_population_tag));
		float employed = float(ws.w.population_s.pop_demographics.get(w.tag, total_employment_tag));

		if(size != 0.0f)
			value = 1.0f - employed / size;
		else
			value = 0.0f;
	}

	template<typename window_type>
	void lifeneed_progress::windowed_update(ui::progress_bar<lifeneed_progress>& bar, window_type& w, world_state& ws) {
		float needs = ws.w.population_s.pops[w.tag].needs_satisfaction;

		if(needs >= 1.0f) 
			bar.set_fraction(1.0f);
		else 
			bar.set_fraction(needs);
	}

	template<typename W>
	void lifeneed_progress_overlay::windowed_update(ui::dynamic_icon<lifeneed_progress_overlay>&, W& w, world_state& ws) {
		value = std::min(1.0f, ws.w.population_s.pops[w.tag].needs_satisfaction);
	}

	template<typename window_type>
	void eveneed_progress::windowed_update(ui::progress_bar<eveneed_progress>& bar, window_type& w, world_state& ws) {
		float needs = ws.w.population_s.pops[w.tag].needs_satisfaction;

		bar.set_fraction(std::clamp(needs - 1.0f, 0.0f, 1.0f));
	}

	template<typename W>
	void eveneed_progress_overlay::windowed_update(ui::dynamic_icon<eveneed_progress_overlay>&, W& w, world_state& ws) {
		value = std::clamp(ws.w.population_s.pops[w.tag].needs_satisfaction - 1.0f, 0.0f, 1.0f);
	}

	template<typename window_type>
	void luxneed_progress::windowed_update(ui::progress_bar<luxneed_progress>& bar, window_type& w, world_state& ws) {
		float needs = ws.w.population_s.pops[w.tag].needs_satisfaction;

		bar.set_fraction(std::clamp(needs - 2.0f, 0.0f, 1.0f));
	}

	template<typename W>
	void luxneed_progress_overlay::windowed_update(ui::dynamic_icon<luxneed_progress_overlay>&, W& w, world_state& ws) {
		value = std::clamp(ws.w.population_s.pops[w.tag].needs_satisfaction - 2.0f, 0.0f, 1.0f);
	}

	template<typename W>
	void pop_revolt::windowed_update(ui::dynamic_icon<pop_revolt>& ico, W& w, world_state& ws) {
		ui::hide(*ico.associated_object);
	}

	template<typename W>
	void pop_movement_social::windowed_update(ui::dynamic_icon<pop_movement_social>& ico, W& w, world_state& ws) {
		ui::hide(*ico.associated_object);
	}

	template<typename W>
	void pop_movement_political::windowed_update(ui::dynamic_icon<pop_movement_political>& ico, W& w, world_state& ws) {
		ui::hide(*ico.associated_object);
	}

	template<typename W>
	void pop_movement_flag::windowed_update(ui::masked_flag<pop_movement_flag>& ico, W& w, world_state& ws) {
		ui::hide(*ico.associated_object);
	}

	template<typename W>
	void pop_country_open_button::windowed_update(ui::simple_button<pop_country_open_button>& button, W& w, world_state& ws) {
		tag = w.tag;

		if(ws.w.population_w.display_type == population_display::nation && tag == ws.w.population_w.population_for_nation)
			button.set_frame(ws.w.gui_m, 1ui32);
		else
			button.set_frame(ws.w.gui_m, 0ui32);
	}

	template<typename W>
	void pop_state_open_button::windowed_update(ui::simple_button<pop_state_open_button>& button, W& w, world_state& ws) {
		tag = w.tag;

		if(ws.w.population_w.display_type == population_display::state && tag == ws.w.population_w.population_for_state)
			button.set_frame(ws.w.gui_m, 1ui32);
		else
			button.set_frame(ws.w.gui_m, 0ui32);
	}

	template<typename W>
	void pop_province_open_button::windowed_update(ui::simple_button<pop_province_open_button>& button, W& w, world_state& ws) {
		tag = w.tag;

		if(ws.w.population_w.display_type == population_display::province && tag == ws.w.population_w.population_for_province)
			button.set_frame(ws.w.gui_m, 1ui32);
		else
			button.set_frame(ws.w.gui_m, 0ui32);
	}

	template<typename window_type>
	void pop_country_name::windowed_update(window_type& win, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		if(is_valid_index(win.tag)) {
			ui::add_linear_text(ui::xy_pair{ 0, 0 }, ws.w.nation_s.nations[win.tag].name, fmt, ws.s.gui_m, ws.w.gui_m, box, lm);
			lm.finish_current_line();
		}
	}

	template<typename window_type>
	void pop_state_name::windowed_update(window_type& win, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		if(is_valid_index(win.tag)) {
			ui::add_linear_text(ui::xy_pair{ 0, 0 }, ws.w.nation_s.states[win.tag].name, fmt, ws.s.gui_m, ws.w.gui_m, box, lm);
			lm.finish_current_line();
		}
	}

	template<typename window_type>
	void pop_province_name::windowed_update(window_type& win, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		if(is_valid_index(win.tag)) {
			ui::add_linear_text(ui::xy_pair{ 0, 0 }, ws.w.province_s.province_state_container[win.tag].name, fmt, ws.s.gui_m, ws.w.gui_m, box, lm);
			lm.finish_current_line();
		}
	}

	template<typename window_type>
	void pop_country_size::windowed_update(window_type& win, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		if(ws.w.nation_s.nations.is_valid_index(win.tag)) {
			char16_t local_buf[32];
			put_value_in_buffer(local_buf, display_type::integer, ws.w.nation_s.nation_demographics.get(win.tag, total_population_tag));

			ui::text_chunk_to_instances(
				ws.s.gui_m,
				ws.w.gui_m,
				vector_backed_string<char16_t>(local_buf),
				box,
				ui::xy_pair{ 0,0 },
				fmt,
				lm);

			lm.finish_current_line();
		}
	}

	template<typename W>
	void pop_country_growth::windowed_update(ui::dynamic_icon<pop_country_growth>& ico, W& w, world_state& ws) {
		if(is_valid_index(w.tag)) {
			auto growth = ws.w.nation_s.nation_demographics.get(w.tag, total_population_tag) - ws.w.nation_s.nations[w.tag].last_population;
			if(growth > 0)
				ico.set_frame(ws.w.gui_m, 0ui32);
			else if(growth == 0)
				ico.set_frame(ws.w.gui_m, 1ui32);
			else
				ico.set_frame(ws.w.gui_m, 2ui32);
		}
	}

	template<typename W>
	void pop_growth::windowed_update(ui::dynamic_icon<pop_growth>& ico, W& w, world_state& ws) {
		auto total_growth = total_size_change(ws.w.population_s.pops[w.tag]);

		if(total_growth > 0)
			ico.set_frame(ws.w.gui_m, 0ui32);
		else if(total_growth == 0)
			ico.set_frame(ws.w.gui_m, 1ui32);
		else
			ico.set_frame(ws.w.gui_m, 2ui32);
	}

	template<typename window_type>
	void pop_state_size::windowed_update(window_type& win, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		if(ws.w.nation_s.states.is_valid_index(win.tag)) {
			char16_t local_buf[32];
			put_value_in_buffer(local_buf, display_type::integer, ws.w.nation_s.state_demographics.get(win.tag, total_population_tag));

			ui::text_chunk_to_instances(
				ws.s.gui_m,
				ws.w.gui_m,
				vector_backed_string<char16_t>(local_buf),
				box,
				ui::xy_pair{ 0,0 },
				fmt,
				lm);

			lm.finish_current_line();
		}
	}

	template<typename W>
	void pop_state_growth::windowed_update(ui::dynamic_icon<pop_state_growth>& ico, W& w, world_state& ws) {
		if(is_valid_index(w.tag)) {
			auto growth = ws.w.nation_s.state_demographics.get(w.tag, total_population_tag) - ws.w.nation_s.states[w.tag].last_population;
			if(growth > 0)
				ico.set_frame(ws.w.gui_m, 0ui32);
			else if(growth == 0)
				ico.set_frame(ws.w.gui_m, 1ui32);
			else
				ico.set_frame(ws.w.gui_m, 2ui32);
		}
	}

	template<typename W>
	void pop_colonial_state_button::windowed_update(ui::simple_button<pop_colonial_state_button>& ico, W& w, world_state& ws) {
		if(is_valid_index(w.tag)) {
			if((ws.w.nation_s.states[w.tag].flags & (nations::state_instance::is_colonial | nations::state_instance::is_protectorate)) != 0) {
				ui::make_visible_immediate(*ico.associated_object);
			} else {
				ui::hide(*ico.associated_object);
			}
		}
	}

	template<typename W>
	void pop_state_focus_button::windowed_update(ui::simple_button<pop_state_focus_button>&, W& w, world_state& ws) {
		tag = w.tag;
	}

	template<typename W>
	void pop_state_expand_button::windowed_update(ui::simple_button<pop_state_expand_button>& button, W& w, world_state& ws) {
		tag = w.tag;
		if(ws.w.population_w.population_window_has_state_expanded(tag))
			button.set_frame(ws.w.gui_m, 1ui32);
		else
			button.set_frame(ws.w.gui_m, 0ui32);
	}

	template<typename window_type>
	void pop_province_size::windowed_update(window_type& win, ui::tagged_gui_object box, ui::text_box_line_manager& lm, ui::text_format& fmt, world_state& ws) {
		if(is_valid_index(win.tag)) {
			char16_t local_buf[32];
			put_value_in_buffer(local_buf, display_type::integer, ws.w.province_s.province_demographics.get(win.tag, total_population_tag));

			ui::text_chunk_to_instances(
				ws.s.gui_m,
				ws.w.gui_m,
				vector_backed_string<char16_t>(local_buf),
				box,
				ui::xy_pair{ 0,0 },
				fmt,
				lm);

			lm.finish_current_line();
		}
	}

	template<typename W>
	void pop_province_growth::windowed_update(ui::dynamic_icon<pop_province_growth>& ico, W& w, world_state& ws) {
		if(is_valid_index(w.tag)) {
			auto growth = ws.w.province_s.province_demographics.get(w.tag, total_population_tag) - ws.w.province_s.province_state_container[w.tag].last_population;
			if(growth > 0)
				ico.set_frame(ws.w.gui_m, 0ui32);
			else if(growth == 0)
				ico.set_frame(ws.w.gui_m, 1ui32);
			else
				ico.set_frame(ws.w.gui_m, 2ui32);
		}
	}

	template<size_t level>
	std::vector<nations::state_tag, concurrent_allocator<nations::state_tag>> pop_tree_view::sub_list(nations::country_tag t, world_state& ws) {
		std::vector<nations::state_tag, concurrent_allocator<nations::state_tag>> result;
		nations::for_each_state(ws, ws.w.nation_s.nations[t], [&result, &ws](nations::state_instance const& si) {
			auto id = si.id;
			if(ws.w.nation_s.states.is_valid_index(id))
				result.push_back(id);
		});
		vector_backed_string_lex_less<char16_t> lss(ws.s.gui_m.text_data_sequences.text_data);
		std::sort(result.begin(), result.end(), [&ws, &lss](nations::state_tag a, nations::state_tag b) {
			return lss(text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences, ws.w.nation_s.states[a].name),
				text_data::text_tag_to_backing(ws.s.gui_m.text_data_sequences, ws.w.nation_s.states[b].name));
		});
		std::stable_sort(result.begin(), result.end(), [&ws](nations::state_tag a, nations::state_tag b) {
			return int32_t(nations::is_colonial_or_protectorate(ws.w.nation_s.states[a])) < int32_t(nations::is_colonial_or_protectorate(ws.w.nation_s.states[b]));
		});
		return result;
	}
	template<size_t level>
	std::vector<provinces::province_tag, concurrent_allocator<provinces::province_tag>> pop_tree_view::sub_list(nations::state_tag t, world_state& ws) {
		std::vector<provinces::province_tag, concurrent_allocator<provinces::province_tag>> result;
		nations::for_each_province(ws, ws.w.nation_s.states[t], [&result](provinces::province_state const& p) { result.push_back(p.id); });
		return result;
	}

	template<typename W>
	void pop_state_base::on_create(W& w, world_state&) {
		w.associated_object->size.x = 215i16;
	}
	template<typename W>
	void pop_province_base::on_create(W& w, world_state&) {
		w.associated_object->size.x = 220i16;
	}
}
