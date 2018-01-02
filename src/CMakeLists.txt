function(define_sources BASE_DIR _SOURCES)

    limix_convert_rel_to_full(FULL_SOURCES ${BASE_DIR} progressbar.c)
    set(${_SOURCES} ${FULL_SOURCES} PARENT_SCOPE)

endfunction(define_sources)
