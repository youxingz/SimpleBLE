#include <stdio.h>
#include <stdlib.h>

#include "simpleble_c/simpleble.h"

// proxy func.
#ifdef __cplusplus
extern "C" {
#endif
typedef simpleble_err_t blex_err_t;
typedef simpleble_adapter_t blex_adapter_t;
typedef simpleble_peripheral_t blex_peripheral_t;

// adapter.h

bool    blex_adapter_is_bluetooth_enabled() {
  return simpleble_adapter_is_bluetooth_enabled();
}

size_t  blex_adapter_get_count() {
  return simpleble_adapter_get_count();
}

blex_adapter_t blex_adapter_get_handle(size_t index) {
  return simpleble_adapter_get_handle(index);
}

void    blex_adapter_release_handle(blex_adapter_t handle) {
  simpleble_adapter_release_handle(handle);
}

char*   blex_adapter_identifier(blex_adapter_t handle) {
  return simpleble_adapter_identifier(handle);
}

char*   blex_adapter_address(blex_adapter_t handle) {
  return simpleble_adapter_address(handle);
}

blex_err_t blex_adapter_scan_start(blex_adapter_t handle) {
  return simpleble_adapter_scan_start(handle);
}

blex_err_t blex_adapter_scan_stop(blex_adapter_t handle) {
  return simpleble_adapter_scan_stop(handle);
}

blex_err_t blex_adapter_scan_is_active(blex_adapter_t handle, bool * active) {
  return simpleble_adapter_scan_is_active(handle, active);
}

blex_err_t blex_adapter_scan_for(blex_adapter_t handle, int timeout_ms) {
  return simpleble_adapter_scan_for(handle, timeout_ms);
}

size_t    blex_adapter_scan_get_results_count(blex_adapter_t handle) {
  return simpleble_adapter_scan_get_results_count(handle);
}

blex_peripheral_t blex_adapter_scan_get_results_handle(blex_adapter_t handle,
                                                              size_t index) {
  return simpleble_adapter_scan_get_results_handle(handle, index);
}

size_t    blex_adapter_get_paired_peripherals_count(blex_adapter_t handle) {
  return simpleble_adapter_get_paired_peripherals_count(handle);
}

blex_peripheral_t blex_adapter_get_paired_peripherals_handle(blex_adapter_t handle,
                                                                    size_t index) {
  return simpleble_adapter_get_paired_peripherals_handle(handle, index);
}

blex_err_t blex_adapter_set_callback_on_scan_start(
      blex_adapter_t handle,
      void (*callback)(blex_adapter_t adapter, void* userdata),
      void* userdata
    ) {
  return simpleble_adapter_set_callback_on_scan_start(handle, callback, userdata);
}

blex_err_t blex_adapter_set_callback_on_scan_stop(
      blex_adapter_t handle,
      void (*callback)(blex_adapter_t adapter, void* userdata),
      void* userdata
    ) {
  return simpleble_adapter_set_callback_on_scan_stop(handle, callback, userdata);
}

blex_err_t blex_adapter_set_callback_on_scan_updated(
    blex_adapter_t handle,
    void (*callback)(blex_adapter_t adapter, blex_peripheral_t peripheral, void* userdata),
    void* userdata
    ) {
  return simpleble_adapter_set_callback_on_scan_updated(handle, callback, userdata);
}

blex_err_t blex_adapter_set_callback_on_scan_found(
    blex_adapter_t handle,
    void (*callback)(blex_adapter_t adapter, blex_peripheral_t peripheral, void* userdata),
    void* userdata) {
  return simpleble_adapter_set_callback_on_scan_found(handle, callback, userdata);
}

// peripheral.h

typedef simpleble_address_type_t blex_address_type_t;
typedef simpleble_service_t blex_service_t;
typedef simpleble_manufacturer_data_t blex_manufacturer_data_t;
typedef simpleble_uuid_t blex_uuid_t;

void blex_peripheral_release_handle(blex_peripheral_t handle) {
  return simpleble_peripheral_release_handle(handle);
}

char* blex_peripheral_identifier(blex_peripheral_t handle) {
  return simpleble_peripheral_identifier(handle);
}

char* blex_peripheral_address(blex_peripheral_t handle) {
  return simpleble_peripheral_address(handle);
}

blex_address_type_t blex_peripheral_address_type(blex_peripheral_t handle) {
  return simpleble_peripheral_address_type(handle);
}

int16_t   blex_peripheral_rssi(blex_peripheral_t handle) {
  return simpleble_peripheral_rssi(handle);
}

int16_t   blex_peripheral_tx_power(blex_peripheral_t handle) {
  return simpleble_peripheral_tx_power(handle);
}

uint16_t  blex_peripheral_mtu(blex_peripheral_t handle) {
  return simpleble_peripheral_mtu(handle);
}

blex_err_t blex_peripheral_connect(blex_peripheral_t handle) {
  return simpleble_peripheral_connect(handle);
}

blex_err_t blex_peripheral_disconnect(blex_peripheral_t handle) {
  return simpleble_peripheral_disconnect(handle);
}

blex_err_t blex_peripheral_is_connected(blex_peripheral_t handle, bool* connected) {
  return simpleble_peripheral_is_connected(handle, connected);
}

blex_err_t blex_peripheral_is_connectable(blex_peripheral_t handle, bool* connectable) {
  return simpleble_peripheral_is_connectable(handle, connectable);
}

blex_err_t blex_peripheral_is_paired(blex_peripheral_t handle, bool* paired) {
  return simpleble_peripheral_is_paired(handle, paired);
}

blex_err_t blex_peripheral_unpair(blex_peripheral_t handle) {
  return simpleble_peripheral_unpair(handle);
}

size_t     blex_peripheral_services_count(blex_peripheral_t handle) {
  return simpleble_peripheral_services_count(handle);
}

blex_err_t blex_peripheral_services_get(blex_peripheral_t handle,
                                                   size_t index,
                                          blex_service_t* services) {
  return simpleble_peripheral_services_get(handle, index, services);
}

size_t     blex_peripheral_manufacturer_data_count(blex_peripheral_t handle) {
  return simpleble_peripheral_manufacturer_data_count(handle);
}

blex_err_t blex_peripheral_manufacturer_data_get(
    blex_peripheral_t handle, size_t index, blex_manufacturer_data_t* manufacturer_data
  ) {
  return simpleble_peripheral_manufacturer_data_get(handle, index, manufacturer_data);
}

blex_err_t blex_peripheral_read(blex_peripheral_t handle,
                                      blex_uuid_t service,
                                      blex_uuid_t characteristic,
                                        uint8_t** data,
                                          size_t* data_length) {
  return simpleble_peripheral_read(handle, service, characteristic, data, data_length);
}

blex_err_t eblex_peripheral_write_request(blex_peripheral_t handle,
                                                blex_uuid_t service,
                                                blex_uuid_t characteristic,
                                             const uint8_t* data,
                                                     size_t data_length) {
  return simpleble_peripheral_write_request(handle, service, characteristic, data, data_length);
}

blex_err_t blex_peripheral_write_command(blex_peripheral_t handle,
                                               blex_uuid_t service,
                                               blex_uuid_t characteristic,
                                            const uint8_t* data,
                                                    size_t data_length) {
  return simpleble_peripheral_write_command(handle, service, characteristic, data, data_length);
}

blex_err_t blex_peripheral_notify(blex_peripheral_t handle,
                                        blex_uuid_t service,
                                        blex_uuid_t characteristic,
                                        void (*callback)(blex_uuid_t service, blex_uuid_t characteristic, const uint8_t* data, size_t data_length, void* userdata),
                                              void* userdata) {
  return simpleble_peripheral_notify(handle, service, characteristic, callback, userdata);
}

blex_err_t blex_peripheral_indicate(blex_peripheral_t handle,
                                          blex_uuid_t service,
                                          blex_uuid_t characteristic,
                                                void (*callback)(blex_uuid_t service, blex_uuid_t characteristic, const uint8_t* data, size_t data_length, void* userdata),
                                                void* userdata) {
  return simpleble_peripheral_indicate(handle, service, characteristic, callback, userdata);
}

blex_err_t blex_peripheral_unsubscribe(blex_peripheral_t handle,
                                             blex_uuid_t service,
                                             blex_uuid_t characteristic) {
  return simpleble_peripheral_unsubscribe(handle, service, characteristic);
}

blex_err_t blex_peripheral_read_descriptor(blex_peripheral_t handle,
                                                 blex_uuid_t service,
                                                 blex_uuid_t characteristic,
                                                 blex_uuid_t descriptor,
                                                   uint8_t** data,
                                                     size_t* data_length) {
  return simpleble_peripheral_read_descriptor(handle, service, characteristic, descriptor, data, data_length);
}

blex_err_t blex_peripheral_write_descriptor(blex_peripheral_t handle,
                                                  blex_uuid_t service,
                                                  blex_uuid_t characteristic,
                                                  blex_uuid_t descriptor,
                                               const uint8_t* data,
                                                       size_t data_length) {
  return simpleble_peripheral_write_descriptor(handle, service, characteristic, descriptor, data, data_length);
}

blex_err_t blex_peripheral_set_callback_on_connected(blex_peripheral_t handle,
                                                                 void (*callback)(blex_peripheral_t peripheral, void* userdata),
                                                                 void* userdata) {
  return simpleble_peripheral_set_callback_on_connected(handle, callback, userdata);
}

blex_err_t blex_peripheral_set_callback_on_disconnected(blex_peripheral_t handle,
                                                                    void (*callback)(blex_peripheral_t peripheral, void* userdata),
                                                                    void* userdata) {
  return simpleble_peripheral_set_callback_on_disconnected(handle, callback, userdata);
}

// logging.h

// typedef simpleble_log_level_t blex_log_level_t;
// typedef simpleble_log_callback_t blex_log_callback_t;

// void blex_logging_set_level(blex_log_level_t level) {
//   simpleble_logging_set_level(level);
// }
// void blex_logging_set_callback(blex_log_callback_t callback) {
//   simpleble_logging_set_callback(callback);
// }


int main() {
  printf("Test BLEX module :: ");
  bool is_enabled = blex_adapter_is_bluetooth_enabled();
  if (is_enabled) {
    printf("BLEX is enabled\n");
  } else {
    printf("BLEX is not enabled\n");
  }
}

#ifdef __cplusplus
}
#endif
