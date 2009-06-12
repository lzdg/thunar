/* $Id$ */
/*-
 * Copyright (c) 2009 Jannis Pohlmann <jannis@xfce.org>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __THUNAR_THUMBNAILER_H__
#define __THUNAR_THUMBNAILER_H__

#include <thunar/thunar-file.h>

G_BEGIN_DECLS;

typedef struct _ThunarThumbnailerClass ThunarThumbnailerClass;
typedef struct _ThunarThumbnailer      ThunarThumbnailer;

#define THUNAR_TYPE_THUMBNAILER            (thunar_thumbnailer_get_type ())
#define THUNAR_THUMBNAILER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), THUNAR_TYPE_THUMBNAILER, ThunarThumbnailer))
#define THUNAR_THUMBNAILER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), THUNAR_TYPE_THUMBNAILER, ThunarThumbnailerClass))
#define THUNAR_IS_THUMBNAILER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THUNAR_TYPE_THUMBNAILER))
#define THUNAR_IS_THUMBNAILER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), THUNAR_TYPE_THUMBNAILER))
#define THUNAR_THUMBNAILER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), THUNAR_TYPE_THUMBNAILER, ThunarThumbnailerClass))

GType              thunar_thumbnailer_get_type          (void) G_GNUC_CONST;

ThunarThumbnailer *thunar_thumbnailer_new               (void) G_GNUC_MALLOC;

gboolean           thunar_thumbnailer_queue_file        (ThunarThumbnailer *generator,
                                                         ThunarFile        *file,
                                                         guint             *handle);
gboolean           thunar_thumbnailer_queue_files       (ThunarThumbnailer *generator,
                                                         GList             *files,
                                                         guint             *handle);
void               thunar_thumbnailer_unqueue           (ThunarThumbnailer *thumbnailer,
                                                         guint              handle);
gboolean           thunar_thumbnailer_file_is_supported (ThunarThumbnailer *thumbnailer,
                                                         ThunarFile        *file);

G_END_DECLS;

#endif /* !__THUNAR_THUMBNAILER_H__ */
