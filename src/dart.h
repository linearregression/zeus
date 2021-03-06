/* * Copyright (c) 2015, Yahoo Inc. All rights reserved.
 * Copyrights licensed under the New BSD License.
 * See the accompanying LICENSE file for terms.
 */

#ifndef DART_H
#define DART_H

#include <string>

#include "generator.h"
#include "ir.h"

struct DartGenerator : public Generator {
  void header(Printer &, const ir::Namespaces &);

  void structure(Printer &, const ir::Structure &);

  void content(Printer &, const Type::TYPES, const std::string &);

  void dimension(Printer &, const ir::DimensionEnumeration &);
  void dimensionClass(Printer &);

  void key(Printer &, const ir::Key &, const ir::Dimensions &);
  void keyDimension(Printer &, const ir::Key &, const ir::Dimension &,
      const ir::Dimensions &, const int);

  void contextClass(Printer &, const ir::Snapshot &);

  void configurationClass(Printer &, const ir::Snapshot &);

  void generate(Printer &, const ir::Snapshot &);

  void value(Printer &, const Value &, const std::string &, const int);

  std::string type(const std::string &, const ir::Kind k = ir::kNone) const;

  bool nativeType(const std::string & s) const {
    return s == "boolean"
      || s == "float"
      || s == "integer"
      || s == "string";
  }

  template < class T >
  bool constructor(const T & t) {
    return ! nativeType(t.type)
      || t.kind == ir::kDynamic
      || t.kind == ir::kArray;
  }
};

#endif //DART_H
