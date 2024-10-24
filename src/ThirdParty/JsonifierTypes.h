#ifndef JSONIFIER_TYPES_H
#define JSONIFIER_TYPES_H

#pragma once

#include "jsonifier/Index.hpp"
#include "TypeSafe.h"
#include "JsonifierCatalog.h"
#include "JsonifierCountry.h"
#include "JsonifierTwitter.h"

template<typename value_type> concept performance_data = std::same_as<std::remove_cvref_t<value_type>, twitter_message>
|| std::same_as<std::remove_cvref_t<value_type>, citm_catalog_message>
|| std::same_as<std::remove_cvref_t<value_type>, canada_message>;

template<> struct jsonifier::core<geometry_data> {
	using value_type = geometry_data;
	static constexpr auto parseValue = createValue<&value_type::type, &value_type::coordinates>();
};

template<> struct jsonifier::core<properties_data> {
	using value_type = properties_data;
	static constexpr auto parseValue = createValue<&value_type::name>();
};

template<> struct jsonifier::core<feature> {
	using value_type = feature;
	static constexpr auto parseValue = createValue<&value_type::properties, &value_type::type, &value_type::geometry>();
};

template<> struct jsonifier::core<canada_message> {
	using value_type = canada_message;
	static constexpr auto parseValue = createValue<&value_type::type, &value_type::features>();
};

template<> struct jsonifier::core<search_metadata_data> {
	using value_type = search_metadata_data;
	static constexpr auto parseValue = createValue<&value_type::completed_in, &value_type::max_id, &value_type::max_id_str, &value_type::next_results, &value_type::query,
		&value_type::refresh_url, &value_type::count, &value_type::since_id, &value_type::since_id_str>();
};

template<> struct jsonifier::core<hashtag_data> {
	using value_type = hashtag_data;
	static constexpr auto parseValue = createValue<&value_type::text, &value_type::indices>();
};

template<> struct jsonifier::core<large_data> {
	using value_type = large_data;
	static constexpr auto parseValue = createValue<&value_type::w, &value_type::h, &value_type::resize>();
};

template<> struct jsonifier::core<sizes_data> {
	using value_type = sizes_data;
	static constexpr auto parseValue = createValue<&value_type::medium, &value_type::small, &value_type::thumb, &value_type::large>();
};

template<> struct jsonifier::core<media_data> {
	using value_type = media_data;
	static constexpr auto parseValue =
		createValue<&value_type::id, &value_type::id_str, &value_type::indices, &value_type::media_url, &value_type::media_url_https, &value_type::url, &value_type::display_url,
		&value_type::expanded_url, &value_type::type, &value_type::sizes, &value_type::source_status_id, &value_type::source_status_id_str>();
};

template<> struct jsonifier::core<url_data> {
	using value_type = url_data;
	static constexpr auto parseValue = createValue<&value_type::url, &value_type::expanded_url, &value_type::display_url, &value_type::indices>();
};

template<> struct jsonifier::core<user_mention> {
	using value_type = user_mention;
	static constexpr auto parseValue = createValue<&value_type::screen_name, &value_type::name, &value_type::id, &value_type::id_str, &value_type::indices>();
};

template<> struct jsonifier::core<status_entities> {
	using value_type = status_entities;
	static constexpr auto parseValue = createValue<&value_type::hashtags, &value_type::symbols, &value_type::urls, &value_type::user_mentions, &value_type::media>();
};

template<> struct jsonifier::core<metadata_data> {
	using value_type = metadata_data;
	static constexpr auto parseValue = createValue<&value_type::result_type, &value_type::iso_language_code>();
};

template<> struct jsonifier::core<description_data> {
	using value_type = description_data;
	static constexpr auto parseValue = createValue<&value_type::urls>();
};

template<> struct jsonifier::core<user_entities> {
	using value_type = user_entities;
	static constexpr auto parseValue = createValue<&value_type::description, &value_type::url>();
};

template<> struct jsonifier::core<twitter_user_data> {
	using value_type = twitter_user_data;
	static constexpr auto parseValue = createValue("id", &value_type::id, "id_str", &value_type::id_str, "name", &value_type::name, "screen_name", &value_type::screen_name,
		"location", &value_type::location, "description", &value_type::description, "url", &value_type::url, "entities", &value_type::entities, "protected",
		&value_type::protectedVal, "followers_count", &value_type::followers_count, "friends_count", &value_type::friends_count, "listed_count", &value_type::listed_count,
		"created_at", &value_type::created_at, "favourites_count", &value_type::favourites_count, "utc_offset", &value_type::utc_offset, "time_zone", &value_type::time_zone,
		"geo_enabled", &value_type::geo_enabled, "verified", &value_type::verified, "statuses_count", &value_type::statuses_count, "lang", &value_type::lang,
		"contributors_enabled", &value_type::contributors_enabled, "is_translator", &value_type::is_translator, "is_translation_enabled", &value_type::is_translation_enabled,
		"profile_background_color", &value_type::profile_background_color, "profile_background_image_url", &value_type::profile_background_image_url,
		"profile_background_image_url_https", &value_type::profile_background_image_url_https, "profile_background_tile", &value_type::profile_background_tile, "profile_image_url",
		&value_type::profile_image_url, "profile_image_url_https", &value_type::profile_image_url_https, "profile_banner_url", &value_type::profile_banner_url,
		"profile_link_color", &value_type::profile_link_color, "profile_sidebar_border_color", &value_type::profile_sidebar_border_color, "profile_sidebar_fill_color",
		&value_type::profile_sidebar_fill_color, "profile_text_color", &value_type::profile_text_color, "profile_use_background_image", &value_type::profile_use_background_image,
		"default_profile", &value_type::default_profile, "default_profile_image", &value_type::default_profile_image, "following", &value_type::following, "follow_request_sent",
		&value_type::follow_request_sent, "notifications", &value_type::notifications);
};

template<> struct jsonifier::core<status_data> {
	using value_type = status_data;
	static constexpr auto parseValue = createValue<&value_type::metadata, &value_type::created_at, &value_type::id, &value_type::id_str, &value_type::text, &value_type::source,
		&value_type::truncated, &value_type::in_reply_to_status_id, &value_type::in_reply_to_status_id_str, &value_type::in_reply_to_user_id, &value_type::in_reply_to_user_id_str,
		&value_type::in_reply_to_screen_name, &value_type::user, &value_type::geo, &value_type::coordinates, &value_type::place, &value_type::contributors,
		&value_type::retweet_count, &value_type::favorite_count, &value_type::entities, &value_type::favorited, &value_type::retweeted, &value_type::lang,
		&value_type::retweeted_status, &value_type::possibly_sensitive>();
};

template<> struct jsonifier::core<twitter_message> {
	using value_type = twitter_message;
	static constexpr auto parseValue = createValue<&value_type::statuses, &value_type::search_metadata>();
};

template<> struct jsonifier::core<audience_sub_category_names> {
	using value_type = audience_sub_category_names;
	static constexpr auto parseValue = createValue("337100890", &value_type::the337100890);
};

template<> struct jsonifier::core<names> {
	using value_type = names;
	static constexpr auto parseValue = createValue();
};

template<> struct jsonifier::core<event> {
	using value_type = event;
	static constexpr auto parseValue = createValue<&value_type::description, &value_type::id, &value_type::logo, &value_type::name, &value_type::subTopicIds,
		&value_type::subjectCode, &value_type::subtitle, &value_type::topicIds>();
};

template<> struct jsonifier::core<price> {
	using value_type = price;
	static constexpr auto parseValue = createValue<&value_type::amount, &value_type::audienceSubCategoryId, &value_type::seatCategoryId>();
};

template<> struct jsonifier::core<area> {
	using value_type = area;
	static constexpr auto parseValue = createValue<&value_type::areaId, &value_type::blockIds>();
};

template<> struct jsonifier::core<seat_category> {
	using value_type = seat_category;
	static constexpr auto parseValue = createValue<&value_type::areas, &value_type::seatCategoryId>();
};

template<> struct jsonifier::core<performance> {
	using value_type = performance;
	static constexpr auto parseValue = createValue<&value_type::eventId, &value_type::id, &value_type::logo, &value_type::name, &value_type::prices, &value_type::seatCategories,
		&value_type::seatMapImage, &value_type::start, &value_type::venueCode>();
};

template<> struct jsonifier::core<venue_names> {
	using value_type = venue_names;
	static constexpr auto parseValue = createValue<&value_type::PLEYEL_PLEYEL>();
};

template<> struct jsonifier::core<citm_catalog_message> {
	using value_type = citm_catalog_message;
	static constexpr auto parseValue =
		createValue<&value_type::areaNames, &value_type::audienceSubCategoryNames, &value_type::blockNames, &value_type::events, &value_type::performances,
		&value_type::seatCategoryNames, &value_type::subTopicNames, &value_type::subjectNames, &value_type::topicNames, &value_type::topicSubTopics, &value_type::venueNames>();
};

template<> struct jsonifier::core<Obj3> {
	using value_type = Obj3;
	static constexpr auto parseValue = createValue<
		&value_type::a,
		&value_type::foo
	>();
};

template<> struct jsonifier::core<Obj2> {
	using value_type = Obj2;
	static constexpr auto parseValue = createValue<
		&value_type::foo
	>();
};

template<typename value_type> jsonifier::vector<value_type> parseJsonArray(jsonifier::vector<jsonifier::raw_json_data> inputData) noexcept {
	jsonifier::vector<value_type> returnValues{};
	for (auto& value : inputData) {
		if constexpr (std::is_same_v<value_type, std::string>) {
			returnValues.emplace_back(static_cast<value_type>(static_cast<jsonifier::string>(value)));
		}
		else {
			returnValues.emplace_back(static_cast<value_type>(value));
		}
	}
	return returnValues;
}

template<const auto& options, typename buffer_type, typename serialize_context_type>
void serializeRawJson(buffer_type& buffer, const Special& rawData, serialize_context_type& serializePair) {
	buffer[serializePair.index] = '{';
	++serializePair.index;
	std::memcpy(&buffer[serializePair.index], "\"integer\":", std::size("\"integer\":") - 1);
	serializePair.index += std::size("\"integer\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.integer, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"real\":", std::size("\"real\":") - 1);
	serializePair.index += std::size("\"real\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.real, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"e\":", std::size("\"e\":") - 1);
	serializePair.index += std::size("\"e\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.e, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"E\":", std::size("\"E\":") - 1);
	serializePair.index += std::size("\"E\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.E, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"\":", std::size("\"\":") - 1);
	serializePair.index += std::size("\"\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.emptyKey, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"zero\":", std::size("\"zero\":") - 1);
	serializePair.index += std::size("\"zero\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.zero, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"one\":", std::size("\"one\":") - 1);
	serializePair.index += std::size("\"one\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.one, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"space\":", std::size("\"space\":") - 1);
	serializePair.index += std::size("\"space\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.space, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"quote\":", std::size("\"quote\":") - 1);
	serializePair.index += std::size("\"quote\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.quote, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"backslash\":", std::size("\"backslash\":") - 1);
	serializePair.index += std::size("\"backslash\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.backslash, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"controls\":", std::size("\"controls\":") - 1);
	serializePair.index += std::size("\"controls\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.controls, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"slash\":", std::size("\"slash\":") - 1);
	serializePair.index += std::size("\"slash\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.slash, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"alpha\":", std::size("\"alpha\":") - 1);
	serializePair.index += std::size("\"alpha\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.alpha, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"ALPHA\":", std::size("\"ALPHA\":") - 1);
	serializePair.index += std::size("\"ALPHA\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.ALPHA, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"digit\":", std::size("\"digit\":") - 1);
	serializePair.index += std::size("\"digit\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.digit, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"0123456789\":", std::size("\"0123456789\":") - 1);
	serializePair.index += std::size("\"0123456789\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.number, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"special\":", std::size("\"special\":") - 1);
	serializePair.index += std::size("\"special\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.special, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"hex\":", std::size("\"hex\":") - 1);
	serializePair.index += std::size("\"hex\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.hex, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"true\":", std::size("\"true\":") - 1);
	serializePair.index += std::size("\"true\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.aTrue, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"false\":", std::size("\"false\":") - 1);
	serializePair.index += std::size("\"false\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.aFalse, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"null\":", std::size("\"null\":") - 1);
	serializePair.index += std::size("\"null\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.null, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"array\":", std::size("\"array\":") - 1);
	serializePair.index += std::size("\"array\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.array, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"object\":", std::size("\"object\":") - 1);
	serializePair.index += std::size("\"object\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.object, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"address\":", std::size("\"address\":") - 1);
	serializePair.index += std::size("\"address\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.address, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"url\":", std::size("\"url\":") - 1);
	serializePair.index += std::size("\"url\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.url, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"comment\":", std::size("\"comment\":") - 1);
	serializePair.index += std::size("\"comment\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.comment, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"# -- --> */\":", std::size("\"# -- --> */\":") - 1);
	serializePair.index += std::size("\"# -- --> */\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.commentKey, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\" s p a c e d \":", std::size("\" s p a c e d \":") - 1);
	serializePair.index += std::size("\" s p a c e d \":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.spaced, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"compact\":", std::size("\"compact\":") - 1);
	serializePair.index += std::size("\"compact\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.compact, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"jsontext\":", std::size("\"jsontext\":") - 1);
	serializePair.index += std::size("\"jsontext\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.jsontext, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"quotes\":", std::size("\"quotes\":") - 1);
	serializePair.index += std::size("\"quotes\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.quotes, buffer, serializePair);

	buffer[serializePair.index++] = ',';
	std::memcpy(&buffer[serializePair.index], "\"\\/\\\\\"\\uCAFE\\uBABE\\uAB98\\uFCDE\\ubcda\\uef4A\\b\\f\\n\\r\\t`1~!@#$%^&*()_+-=[]{}|;:',./<>?\":",
		std::size("\"\\/\\\\\"\\uCAFE\\uBABE\\uAB98\\uFCDE\\ubcda\\uef4A\\b\\f\\n\\r\\t`1~!@#$%^&*()_+-=[]{}|;:',./<>?\":") - 1);
	serializePair.index += std::size("\"\\/\\\\\"\\uCAFE\\uBABE\\uAB98\\uFCDE\\ubcda\\uef4A\\b\\f\\n\\r\\t`1~!@#$%^&*()_+-=[]{}|;:',./<>?\":") - 1;
	jsonifier_internal::serialize<options>::impl(rawData.key, buffer, serializePair);

	buffer[serializePair.index] = '}';
	++serializePair.index;
	return;
}

Special parseRawJson(const jsonifier::raw_json_data& rawData) {
	auto specialData = rawData.operator std::unordered_map<jsonifier::string_base<char, 0>, jsonifier::raw_json_data, std::hash<jsonifier::string_base<char, 0>>,
		std::equal_to<jsonifier::string_base<char, 0>>, std::allocator<std::pair<const jsonifier::string, jsonifier::raw_json_data>>>();

	Special specialStruct;
	specialStruct.integer = specialData["integer"].operator int64_t();
	specialStruct.real = specialData["real"].operator double();
	specialStruct.e = specialData["e"].operator double();
	specialStruct.E = specialData["E"].operator double();
	specialStruct.emptyKey = specialData[""].operator double();
	specialStruct.zero = specialData["zero"].operator int64_t();
	specialStruct.one = specialData["one"].operator int64_t();
	specialStruct.space = specialData["space"].operator jsonifier::string();
	specialStruct.quote = specialData["quote"].operator jsonifier::string();
	specialStruct.backslash = specialData["backslash"].operator jsonifier::string();
	specialStruct.controls = specialData["controls"].operator jsonifier::string();
	specialStruct.slash = specialData["slash"].operator jsonifier::string();
	specialStruct.alpha = specialData["alpha"].operator jsonifier::string();
	specialStruct.ALPHA = specialData["ALPHA"].operator jsonifier::string();
	specialStruct.digit = specialData["digit"].operator jsonifier::string();
	specialStruct.number = specialData["0123456789"].operator jsonifier::string();
	specialStruct.special = specialData["special"].operator jsonifier::string();
	specialStruct.hex = specialData["hex"].operator jsonifier::string();
	specialStruct.aTrue = specialData["true"].operator bool();
	specialStruct.aFalse = specialData["false"].operator bool();
	specialStruct.null = nullptr;
	auto newArray = specialData["array"].operator jsonifier::vector<jsonifier::raw_json_data>();
	specialStruct.array = parseJsonArray<int64_t>(newArray);
	specialStruct.object = Empty{};
	specialStruct.address = specialData["address"].operator jsonifier::string();
	specialStruct.url = specialData["url"].operator jsonifier::string();
	specialStruct.comment = specialData["comment"].operator jsonifier::string();
	specialStruct.commentKey = specialData["# -- --> */"].operator jsonifier::string();
	newArray = specialData[" s p a c e d "].operator jsonifier::vector<jsonifier::raw_json_data>();
	specialStruct.spaced = parseJsonArray<int64_t>(newArray);
	newArray = specialData["compact"].operator jsonifier::vector<jsonifier::raw_json_data>();
	specialStruct.compact = parseJsonArray<int64_t>(newArray);
	specialStruct.jsontext = specialData["jsontext"].operator jsonifier::string();
	specialStruct.quotes = specialData["quotes"].operator jsonifier::string();
	specialStruct.key = specialData["\\/\\\\\"\\uCAFE\\uBABE\\uAB98\\uFCDE\\ubcda\\uef4A\\b\\f\\n\\r\\t`1~!@#$%^&*()_+-=[]{}|;:',./<>?"].operator jsonifier::string();
	for (auto& [key, value] : specialData) {
		if (key.find("1~!@#$%^&*()_+-=[]{}|;") != std::string::npos) {
			specialStruct.key = static_cast<std::string>(value.operator jsonifier::string());
		}
	}
	return specialStruct;
}

template<> struct jsonifier::core<Empty> {
	using value_type = Empty;
	static constexpr auto parseValue = createValue();
};

template<typename value_type>
concept special_type = std::is_same_v<Special, std::remove_cvref_t<value_type>>;

namespace jsonifier_internal {

	template<jsonifier::serialize_options options, special_type value_type, jsonifier::concepts::buffer_like buffer_type, typename serialize_context_type>
	struct serialize_impl<options, value_type, buffer_type, serialize_context_type> {
		JSONIFIER_MAYBE_ALWAYS_INLINE static void impl(value_type& value, buffer_type& buffer, serialize_context_type& serializePair) noexcept {
			serializeRawJson<options>(buffer, value, serializePair);
		}
	};

	template<bool minified, jsonifier::parse_options options, typename parse_context_type> struct parse_impl<minified, options, Special, parse_context_type> {
		JSONIFIER_ALWAYS_INLINE static void impl(Special& value, parse_context_type& context) noexcept {
			jsonifier::raw_json_data rawData{};
			parse_impl<minified, options, jsonifier::raw_json_data, parse_context_type>::impl(rawData, context);
			value = parseRawJson(rawData);
		}
	};
}


namespace JsonifierTypes
{
	jsonifier::jsonifier_core<true> parser{};
	class VectorDouble : public TestAction
	{
	public:
		virtual bool ParseDouble(const char* json, long double& reply) const
		{
			std::vector<double> data;
			if (parser.parseJson(data, jsonifier::string_view{ json })) {
				if (data.size() == 1) {
					reply = data[0];
				}
			}
			return true;
		}
	};

	class VectorString : public TestAction
	{
	public:
		virtual bool ParseString(const char* json, std::string& reply) const
		{
			std::vector<std::string> data;
			if (parser.parseJson(data, jsonifier::string_view{ json })) {
				if (data.size() == 1) {
					reply = data[0];
				}
			}
			return true;
		}
	};
}

template<typename T>
struct GetValueResult : public ParseResultBase
{
	T       data;
};

template<typename T> struct jsonifier::core<GetValueResult<T>> {
	using value_type = GetValueResult<T>;
	static constexpr auto parseValue =
		createValue(&value_type::data);
};

namespace JsonifierTypes {

	template<typename T>
	class GetValue : public TestAction
	{

	public:
		virtual JSONIFIER_ALWAYS_INLINE bool Parse(const char* json, size_t length, std::unique_ptr<ParseResultBase>& reply) const
		{
			std::unique_ptr<GetValueResult<T>>    parsedData = std::make_unique<GetValueResult<T>>();
			if (parser.parseJson < jsonifier::parse_options{ .knownOrder = true } > (parsedData->data, jsonifier::string_view{ json, length })) {
				reply = std::move(parsedData);
			}
			return true;
		}
		virtual JSONIFIER_ALWAYS_INLINE bool Stringify(const ParseResultBase& parsedData, std::unique_ptr<StringResultBase>& reply)  const
		{
			GetValueResult<T>const& parsedDataInput = static_cast<GetValueResult<T> const&>(parsedData);
			reply.reset(new StringResultUsingString{});
			parser.serializeJson(parsedDataInput.data, static_cast<StringResultUsingString*>(reply.get())->result);
			return true;
		}
		virtual JSONIFIER_ALWAYS_INLINE bool Prettify(const ParseResultBase& parsedData, std::unique_ptr<StringResultBase>& reply) const
		{
			GetValueResult<T>const& parsedDataInput = static_cast<GetValueResult<T> const&>(parsedData);
			reply.reset(new StringResultUsingString{});
			parser.serializeJson < jsonifier::serialize_options{ .prettify = true } > (parsedDataInput.data, static_cast<StringResultUsingString*>(reply.get())->result);
			return true;
		}
	};

}

#endif
