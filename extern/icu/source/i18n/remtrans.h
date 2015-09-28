/*
**********************************************************************
*   Copyright (c) 2001-2003, International Business Machines
*   Corporation and others.  All Rights Reserved.
**********************************************************************
*   Date        Name        Description
*   04/02/2001  aliu        Creation.
**********************************************************************
*/
#ifndef REMTRANS_H
#define REMTRANS_H

#include "unicode/utypes.h"

#if !UCONFIG_NO_TRANSLITERATION

#include "unicode/translit.h"

U_NAMESPACE_BEGIN

/**
 * A transliterator that removes text.
 * @author Alan Liu
 */
class U_I18N_API RemoveTransliterator : public Transliterator {

public:

    /**
     * Constructs a transliterator.
     */
    RemoveTransliterator();

    /**
     * Destructor.
     */
    virtual ~RemoveTransliterator();

    /**
     * System registration hook.
     */
    static void registerIDs();

    /**
     * Transliterator API.
     * @return A copy of the object.
     */
    Transliterator* clone(void) const;

    /**
     * Implements {@link Transliterator#handleTransliterate}.
     * @param text          the buffer holding transliterated and
     *                      untransliterated text
     * @param offset        the start and limit of the text, the position
     *                      of the cursor, and the start and limit of transliteration.
     * @param incremental   if true, assume more text may be coming after
     *                      pos.contextLimit. Otherwise, assume the text is complete.
     */
    virtual void handleTransliterate(Replaceable& text, UTransPosition& offset,
                                     UBool isIncremental) const;

    /**
     * ICU "poor man's RTTI", returns a UClassID for the actual class.
     *
     * @draft ICU 2.2
     */
    virtual UClassID getDynamicClassID() const;

    /**
     * ICU "poor man's RTTI", returns a UClassID for this class.
     *
     * @draft ICU 2.2
     */
    static UClassID getStaticClassID();

 private:

    /**
     * Factory method
     */
    static Transliterator* _create(const UnicodeString& ID, Token context);
};

U_NAMESPACE_END

#endif /* #if !UCONFIG_NO_TRANSLITERATION */

#endif