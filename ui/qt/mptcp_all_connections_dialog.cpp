/* sctp_all_assocs_dialog.cpp
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "mptcp_all_connections_dialog.h"
#include "ui_mptcp_all_connections_dialog.h"
//#include "ui_sctp_all_assocs_dialog.h"
//#include "sctp_assoc_analyse_dialog.h"

#include "qt_ui_utils.h"
//#include "wireshark_application.h"
#include "file.h"
#include "ui/qt/main_window.h"

#include <QWidget>
#include <QDir>
#include <QFileDialog>
#include <QPushButton>

//#include <QDebug>

MPTCPAllConnectionsDialog::MPTCPAllConnectionsDialog(QWidget *parent, capture_file *cf) :
    QDialog(parent),
    ui(new Ui::MPTCPAllConnectionsDialog),
    cap_file_(cf)
{
    ui->setupUi(this);
//    sctp_assocs = (sctp_allassocs_info_t *)g_malloc(sizeof(sctp_allassocs_info_t));
    fillTable();
}

MPTCPAllConnectionsDialog::~MPTCPAllConnectionsDialog()
{
    delete ui;
}

void MPTCPAllConnectionsDialog::fillTable()
{
    // GSList / GLIST
    QString output;
//    GList *list;
//    sctp_assoc_info_t* assinfo;
    int numAssocs;

    ui->assocList->setColumnHidden(0, true);
    ui->assocList->setColumnWidth(1,  85);
    ui->assocList->setColumnWidth(2,  85);
    ui->assocList->setColumnWidth(3,  150);
    ui->assocList->setColumnWidth(4,  150);

//    sctp_assocs = (sctp_allassocs_info_t*)sctp_stat_get_info();
//    if (sctp_stat_get_info()->is_registered == FALSE) {
//        register_tap_listener_sctp_stat();
//        /*  (redissect all packets) */
//        cf_retap_packets(cap_file_);
//    }
    numAssocs = 0;
//    ui->assocList->setRowCount(g_list_length(sctp_assocs->assoc_info_list));
    ui->assocList->setRowCount( 2 );

//    list = g_slist_first(sctp_assocs->assoc_info_list);

//    while (list) {
    while (numAssocs < 2) {
//        assinfo = (sctp_assoc_info_t*)(list->data);
        ui->assocList->setItem(numAssocs, 0, new QTableWidgetItem(QString("%1").arg(3)));
        ui->assocList->setItem(numAssocs, 1, new QTableWidgetItem(QString("%1").arg(42)));
//        ui->assocList->setItem(numAssocs, 2, new QTableWidgetItem(QString("%1").arg(assinfo->port2)));
//        ui->assocList->setItem(numAssocs, 3, new QTableWidgetItem(QString("%1").arg(assinfo->n_packets)));
//        ui->assocList->setItem(numAssocs, 4, new QTableWidgetItem(QString("%1").arg(assinfo->n_data_chunks)));
//        ui->assocList->setItem(numAssocs, 5, new QTableWidgetItem(QString("%1").arg(assinfo->n_data_bytes)));
//        list = g_list_next(list);
        numAssocs++;
    }
    ui->analyseButton->setEnabled(false);
    ui->setFilterButton->setEnabled(false);
//    connect(ui->assocList, SIGNAL(itemSelectionChanged()), this, SLOT(getSelectedItem()));
}

 // To convert to string
 //get_conversation_port
 //get_conversation_address
 //nstime_to_sec
//         col_str = QString("%L1").arg(packets);
//        setText(CONV_COLUMN_PACKETS, col_str);
//sctp_assoc_info_t* MPTCPAllConnectionsDialog::findSelectedAssoc()
//{
//    QTableWidgetItem *selection;
//    GList *list;
//    sctp_assoc_info_t* assinfo;
//    int row, id;
//
//    selection = ui->assocList->selectedItems()[0];
//    row = selection->row();
//    selection = ui->assocList->item(row, 0);
//    id = (selection->data(0)).toInt();
//    list = g_list_first(sctp_assocs->assoc_info_list);
//
//    while (list) {
//        assinfo = (sctp_assoc_info_t*)(list->data);
//        if (assinfo->assoc_id == id) {
//            return assinfo;
//        }
//        list = g_list_next(list);
//    }
//    return NULL;
//}

//void MPTCPAllConnectionsDialog::currentFlow()
//{
//    ui->analyseButton->setEnabled(true);
//    ui->setFilterButton->setEnabled(true);
//    ui->analyseButton->setFocus(Qt::OtherFocusReason);
////    selected_assoc = findSelectedAssoc();
//    //currentFlow
//    printf("selection changed assoc now %p with id %d\n",
//           selected_assoc, selected_assoc->assoc_id);
//}

void MPTCPAllConnectionsDialog::on_showSubflows_clicked()
{
  // l'important c de pvr exporter en CSV cf conversation_dialog.h
}

void MPTCPAllConnectionsDialog::on_analyseButton_clicked()
{

//    if (!selected_assoc) {
//        selected_assoc = findSelectedAssoc();
//        printf("on_analyseButton_clicked found assoc %p with id %d\n",
//               selected_assoc, selected_assoc->assoc_id);
//    }
//
//    SCTPAssocAnalyseDialog *sctp_analyse = new SCTPAssocAnalyseDialog(this, selected_assoc, cap_file_, this);
//    connect(sctp_analyse, SIGNAL(filterPackets(QString&,bool)),
//            parent(), SLOT(filterPackets(QString&,bool)));
//
//    if (sctp_analyse->isMinimized() == true)
//    {
//        sctp_analyse->showNormal();
//    }
//    else
//    {
//        sctp_analyse->show();
//    }
//
//    sctp_analyse->raise();
//    sctp_analyse->activateWindow();
}

void MPTCPAllConnectionsDialog::on_setFilterButton_clicked()
{
//    guint32 stream_id = selected_master->mptcp_analysis->stream;
//    if (!selected_assoc){
//        selected_assoc = findSelectedAssoc();
//        printf("on_setFilterButton_clicked found assoc %p with id %d\n",
//               selected_assoc, selected_assoc->assoc_id);
//    }
//
//    QString newFilter = QString("tcp.options.mptcp.stream==%1").arg();
//    selected_assoc = NULL;
//    emit filterPackets(newFilter, false);
}

/*
 * Editor modelines
 *
 * Local Variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * ex: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
