// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TYPE_OBJECT_TYPE_FACTORY_H
#define TYPE_OBJECT_TYPE_FACTORY_H

#include <fastrtps/types/TypeObject.h>
#include <fastrtps/types/DynamicTypeBuilder.h>
#include <fastrtps/types/DynamicTypeBuilderPtr.h>
#include <fastrtps/types/DynamicTypePtr.h>
#include <mutex>

namespace eprosima {
namespace fastrtps {
namespace types {

class TypeObjectFactory
{
private:
    mutable std::recursive_mutex m_MutexIdentifiers;
    mutable std::recursive_mutex m_MutexObjects;
    mutable std::recursive_mutex m_MutexInformations;

protected:
    TypeObjectFactory();
    mutable std::map<const std::string, const TypeIdentifier*> identifiers_; // Basic, builtin and EK_MINIMAL
    std::map<const std::string, const TypeIdentifier*> complete_identifiers_; // Only EK_COMPLETE
    std::map<const TypeIdentifier*, const TypeObject*> objects_; // EK_MINIMAL
    std::map<const TypeIdentifier*, const TypeObject*> complete_objects_; // EK_COMPLETE
    mutable std::vector<TypeIdentifier*> identifiers_created_;
    mutable std::map<const TypeIdentifier*, TypeInformation*> informations_;
    mutable std::vector<TypeInformation*> informations_created_;
    std::map<std::string, std::string> aliases_; // Aliases

    DynamicType_ptr build_dynamic_type(
            TypeDescriptor& descriptor,
            const TypeObject* object,
            const DynamicType_ptr annotation_member_type = DynamicType_ptr(nullptr)) const;

    const TypeIdentifier* try_get_complete(
            const TypeIdentifier* identifier) const;

    const TypeIdentifier* get_stored_type_identifier(
            const TypeIdentifier* identifier) const;

    std::string generate_name_and_store_type_identifier(
            const TypeIdentifier* identifier) const;

    void nullify_all_entries(
            const TypeIdentifier* identifier);

    void apply_type_annotations(
            DynamicTypeBuilder_ptr& type_builder,
            const AppliedAnnotationSeq& annotations) const;

    void apply_member_annotations(
            DynamicTypeBuilder_ptr& parent_type_builder,
            MemberId member_id,
            const AppliedAnnotationSeq& annotations) const;

    std::string get_key_from_hash(
            const DynamicType_ptr annotation_descriptor_type,
            const NameHash& hash) const;

    /**
     * @brief Fills the TypeInformation provided with the minimal TypeIdentifiers and its minimal dependencies.
     * @param info
     * @param ident
     */
    void fill_minimal_information(
            TypeInformation* info,
            const TypeIdentifier* ident) const;

    /**
     * @brief Fills the TypeInformation provided with the complete TypeIdentifiers and its complete dependencies
     * if possible, or minimal ones in other case.
     * @param info
     * @param ident
     */
    void fill_complete_information(
            TypeInformation* info,
            const TypeIdentifier* ident) const;

    /**
     * @brief Auxiliar function to fill minimal dependencies.
     * @param info
     * @param identifier
     */
    void fill_minimal_dependant_types(
            TypeInformation* info,
            const TypeIdentifier* identifier) const;

    /**
     * @brief Auxiliar function to fill complete dependencies.
     * @param info
     * @param identifier
     */
    void fill_complete_dependant_types(
            TypeInformation* info,
            const TypeIdentifier* identifier) const;

    /**
     * @brief Auxiliar function to fill minimal information with complete dependencies.
     * @param info
     * @param identifier
     */
    void fill_complete_minimal_dependant_types(
            TypeInformation* info,
            const TypeIdentifier* identifier) const;

public:

    /**
     * @brief Returns the TypeObjectFactory singleton instance.
     *
     * @return A raw pointer to the TypeObjectFactory singleton instance.
     */
    RTPS_DllAPI static TypeObjectFactory* get_instance();

    /**
     * @brief Delete the TypeObjectFactory singleton instance.
     *
     * @return RETCODE_OK if correctly deleted.
     *         RETCODE_ERROR if the singleton instance is not initialized.
     */
    RTPS_DllAPI static ReturnCode_t delete_instance();

    ~TypeObjectFactory();

    /**
     * @brief Retrieve the TypeInformation of the named type.
     *
     * @param type_name Name of the type which TypeInformation is queried.
     * @return Pointer to the TypeInformation of the given type name.
     *         If no TypeInformation is available, nullptr is returned.
     */
    RTPS_DllAPI const TypeInformation* get_type_information(
            const std::string &type_name) const;

    /**
     * @brief Retrieve the TypeInformation of the given TypeIdentifier.
     *
     * @param identifier TypeIdentifier which TypeInformation is queried.
     * @return Pointer to the TypeInformation of the given TypeIdentifier.
     *         If no TypeInformation is available, nullptr is returned.
     */
    RTPS_DllAPI TypeInformation* get_type_information(
            const TypeIdentifier* identifier) const;

    /**
     * @brief Retrieve the TypeObject of the named type.
     *
     * @param type_name Name of the type which TypeObject is queried.
     * @param complete Flag to return either the complete or the minimal TypeObject.
     *                 Default value: minimal TypeObject.
     * @return Pointer to the TypeObject of the given type name.
     *         If the TypeObject is not known, nullptr is returned.
     */
    RTPS_DllAPI const TypeObject* get_type_object(
            const std::string& type_name,
            bool complete = false) const;

    /**
     * @brief Retrieve the TypeObject of the given TypeIdentifier.
     *
     * @param identifier TypeIdentifier which TypeObject is queried.
     * @return Pointer to the TypeObject of the given TypeIdentifier. The returned TypeObject is consistent with the
     *         given TypeIdentifier: a minimal TypeIdentifier returns a minimal TypeObject and a complete TypeIdentifier
     *         returns a minimal TypeObject.
     *         If the TypeObject is not known, nullptr is returned.
     */
    RTPS_DllAPI const TypeObject* get_type_object(
            const TypeIdentifier* identifier) const;

    RTPS_DllAPI TypeKind get_type_kind(
            const std::string& type_name) const;

    RTPS_DllAPI std::string get_type_name(
            const TypeKind kind) const;

    RTPS_DllAPI std::string get_type_name(
            const TypeIdentifier* identifier) const;

    RTPS_DllAPI const TypeIdentifier* get_primitive_type_identifier(
            TypeKind kind) const;

    /**
     * @brief Retrieve the TypeIdentifier of the named type.
     *
     * @param type_name Name of the type which TypeIdentifier is queried.
     * @param complete Flag to return either the complete or the minimal TypeIdentifier.
     *                 Default value: minimal TypeIdentifier.
     * @return Pointer to the TypeIdentifier of the given type name.
     *         If the TypeIdentifier is not known, nullptr is returned.
     */
    RTPS_DllAPI const TypeIdentifier* get_type_identifier(
            const std::string& type_name,
            bool complete = false) const;

    /**
     * @brief Retrieve the TypeIdentifier of the named type.
     *        The complete TypeIdentifier is queried first and if not found the minimal TypeIdentifier is queried.
     *
     * @param type_name Name of the type which TypeIdentifier is queried.
     * @return Pointer to the TypeIdentifier of the given type name.
     *         If the TypeIdentifier is not known, nullptr is returned.
     */
    RTPS_DllAPI const TypeIdentifier* get_type_identifier_trying_complete(
            const std::string& type_name) const;

    RTPS_DllAPI const TypeIdentifier* get_string_identifier(
            uint32_t bound,
            bool wide = false);

    RTPS_DllAPI const TypeIdentifier* get_sequence_identifier(
            const std::string& type_name,
            uint32_t bound,
            bool complete = false);

    RTPS_DllAPI const TypeIdentifier* get_array_identifier(
            const std::string& type_name,
            const std::vector<uint32_t> &bound,
            bool complete = false);

    RTPS_DllAPI const TypeIdentifier* get_map_identifier(
            const std::string& key_type_name,
            const std::string& value_type_name,
            uint32_t bound,
            bool complete = false);

    RTPS_DllAPI DynamicType_ptr build_dynamic_type(
            const std::string& name,
            const TypeIdentifier* identifier,
            const TypeObject* object = nullptr) const;

    /**
     * @brief Check if a given TypeIdentifier is COMPLETE (XTYPES v1.3 Clause 7.3.4.6.6)
     *
     * These are HASH TypeIdentifiers that involve hashing serialized COMPLETE TypeObjects.
     * They consist of:
     *     - those with discriminator EK_COMPLETE
     *     - those with discriminator TI_STRONG_COMPONENT where the contained TypeObjectHashId has discriminator
     *       EK_COMPLETE (TODO: not yet supported)
     *     - those for plain collections where the contained PlainCollectionHeader EquivalenceKind is EK_COMPLETE
     *
     * @param identifier TypeIdentifier to check its completeness
     * @return true if the given TypeIdentifier is COMPLETE.
     *         false otherwise.
     */
    RTPS_DllAPI bool is_type_identifier_complete(
            const TypeIdentifier* identifier) const;

    RTPS_DllAPI void add_type_identifier(
            const std::string& type_name,
            const TypeIdentifier* identifier);

    RTPS_DllAPI void add_type_object(
            const std::string& type_name,
            const TypeIdentifier* identifier,
            const TypeObject* object);

    RTPS_DllAPI inline void add_alias(
            const std::string& alias_name,
            const std::string& target_type)
    {
        std::unique_lock<std::recursive_mutex> scoped(m_MutexIdentifiers);
        aliases_.emplace(std::pair<std::string, std::string>(alias_name, target_type));
    }

    /**
     * @brief Returns a TypeIdentifierWithSizeSeq object filled with the dependencies of the
     * given identifiers. If continuation_point isn't empty, then it will skip the first
     * (max_size * continuation_point) dependencies.
     * @param identifiers
     * @param in_continuation_point
     * @param out_continuation_point
     * @param max_size
     * @return
     */
    RTPS_DllAPI TypeIdentifierWithSizeSeq typelookup_get_type_dependencies(
            const TypeIdentifierSeq& identifiers,
            const OctetSeq& in_continuation_point,
            OctetSeq& out_continuation_point,
            size_t max_size) const;

    /**
     * @brief Fills the given object with the complete version of the given identifier.
     * If the given identifier was MINIMAL, then it will return the stored COMPLETE identifier pointer.
     * Otherwise, it will return the given identifier address (to make comparision trivial).
     * @param identifier
     * @param object
     * @return
     */
    RTPS_DllAPI const TypeIdentifier* typelookup_get_type(
            const TypeIdentifier& identifier,
            TypeObject& object) const;

    /**
     * @brief Checks if a TypeIdentifier is already known by the factory.
     * @param identifier
     * @return
     */
    RTPS_DllAPI bool typelookup_check_type_identifier(
            const TypeIdentifier& identifier) const;

    /**
     * @brief Retrieves the CompleteTypeObject from the given TypeInformation.
     * If it doesn't exist, it returns nullptr.
     * A user that received a TypeInformation from TypeLookupService that calls this method and returns nullptr,
     * must iterate through the TypeInformation dependencies calling recursively to getTypeDependencies method in
     * its participant (which will call the correspondent method in the TypeLookupService), retrieving the
     * TypeObject correspondent and registering the type into the Factory with a name using the add_type_object method,
     * for each COMPLETE TypeIdentifier received in this way until all the hierarchy is registered, and then,
     * the user may call again this method that should return the TypeObject.
     * @param information
     * @return
     */
    RTPS_DllAPI const TypeObject* typelookup_get_type_object_from_information(
            const TypeInformation& information) const;
};

} // namespace types
} // namespace fastrtps
} // namespace eprosima

#endif // TYPE_OBJECT_TYPE_FACTORY_H
