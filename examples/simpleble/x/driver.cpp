#include <stdio.h>
#include <stdlib.h>

#include "simpleble_c/simpleble.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define BLEX_EXPORT __declspec(dllexport)
#else
#define BLEX_EXPORT
#endif

// proxy func.
#ifdef __cplusplus
extern "C" {
#endif
BLEX_EXPORT typedef simpleble_err_t BlexErrorCode;
BLEX_EXPORT typedef simpleble_adapter_t BlexAdapter;
BLEX_EXPORT typedef simpleble_peripheral_t BlexPeripheral;
BLEX_EXPORT typedef simpleble_address_type_t BlexAddressType;
BLEX_EXPORT typedef simpleble_service_t BlexService;
BLEX_EXPORT typedef simpleble_manufacturer_data_t BlexManufacturerData;
BLEX_EXPORT typedef simpleble_uuid_t BlexUUID;

static inline BlexUUID to_uuid(char* uuid) {
  BlexUUID uuid_;
  for (uint8_t i = 0; i < 37; i++) {
    uuid_.value[i] = uuid[i];
  }
  return uuid_;
}

// adapter.h

BLEX_EXPORT bool    blexAdapterIsBluetoothEnabled() {
  return simpleble_adapter_is_bluetooth_enabled();
}

BLEX_EXPORT size_t  blexAdapterGetCount() {
  return simpleble_adapter_get_count();
}

BLEX_EXPORT BlexAdapter blexAdapterGetHandle(size_t index) {
  return simpleble_adapter_get_handle(index);
}

BLEX_EXPORT void    blexAdapterReleaseHandle(BlexAdapter handle) {
  simpleble_adapter_release_handle(handle);
}

BLEX_EXPORT char*   blexAdapterIdentifier(BlexAdapter handle) {
  return simpleble_adapter_identifier(handle);
}

BLEX_EXPORT char*   blexAdapterAddress(BlexAdapter handle) {
  return simpleble_adapter_address(handle);
}

BLEX_EXPORT BlexErrorCode blexAdapterScanStart(BlexAdapter handle) {
  return simpleble_adapter_scan_start(handle);
}

BLEX_EXPORT BlexErrorCode blexAdapterScanStop(BlexAdapter handle) {
  return simpleble_adapter_scan_stop(handle);
}

BLEX_EXPORT BlexErrorCode blexAdapterScanIsActive(BlexAdapter handle, bool * active) {
  return simpleble_adapter_scan_is_active(handle, active);
}

BLEX_EXPORT BlexErrorCode blexAdapterScanFor(BlexAdapter handle, int timeout_ms) {
  return simpleble_adapter_scan_for(handle, timeout_ms);
}

BLEX_EXPORT size_t    blexAdapterScanGetResultsCount(BlexAdapter handle) {
  return simpleble_adapter_scan_get_results_count(handle);
}

BLEX_EXPORT BlexPeripheral blexAdapterScanGetResultsHandle(BlexAdapter handle,
                                                    size_t index) {
  return simpleble_adapter_scan_get_results_handle(handle, index);
}

BLEX_EXPORT size_t    blexAdapterGetPairedPeripheralsCount(BlexAdapter handle) {
  return simpleble_adapter_get_paired_peripherals_count(handle);
}

BLEX_EXPORT BlexPeripheral blexAdapterGetPairedPeripheralsHandle(BlexAdapter handle,
                                                          size_t index) {
  return simpleble_adapter_get_paired_peripherals_handle(handle, index);
}

BLEX_EXPORT BlexErrorCode blexAdapterSetCallbackOnScanStart(
      BlexAdapter handle,
      void (*callback)(BlexAdapter adapter, void* userdata),
      void* userdata
    ) {
  return simpleble_adapter_set_callback_on_scan_start(handle, callback, userdata);
}

BLEX_EXPORT BlexErrorCode blexAdapterSetCallbackOnScanStop(
      BlexAdapter handle,
      void (*callback)(BlexAdapter adapter, void* userdata),
      void* userdata
    ) {
  return simpleble_adapter_set_callback_on_scan_stop(handle, callback, userdata);
}

BLEX_EXPORT BlexErrorCode blexAdapterSetCallbackOnScanUpdated(
    BlexAdapter handle,
    void (*callback)(BlexAdapter adapter, BlexPeripheral peripheral, void* userdata),
    void* userdata
    ) {
  return simpleble_adapter_set_callback_on_scan_updated(handle, callback, userdata);
}

BLEX_EXPORT BlexErrorCode blexAdapterSetCallbackOnScanFound(
    BlexAdapter handle,
    void (*callback)(BlexAdapter adapter, BlexPeripheral peripheral, void* userdata),
    void* userdata) {
  return simpleble_adapter_set_callback_on_scan_found(handle, callback, userdata);
}

// peripheral.h

BLEX_EXPORT void blexPeripheralReleaseHandle(BlexPeripheral handle) {
  simpleble_peripheral_release_handle(handle);
}

BLEX_EXPORT char* blexPeripheralIdentifier(BlexPeripheral handle) {
  return simpleble_peripheral_identifier(handle);
}

BLEX_EXPORT char* blexPeripheralAddress(BlexPeripheral handle) {
  return simpleble_peripheral_address(handle);
}

BLEX_EXPORT BlexAddressType blexPeripheralAddressType(BlexPeripheral handle) {
  return simpleble_peripheral_address_type(handle);
}

BLEX_EXPORT int16_t   blexPeripheralRssi(BlexPeripheral handle) {
  return simpleble_peripheral_rssi(handle);
}

BLEX_EXPORT int16_t   blexPeripheralPower(BlexPeripheral handle) {
  return simpleble_peripheral_tx_power(handle);
}

BLEX_EXPORT uint16_t  blexPeripheralMtu(BlexPeripheral handle) {
  return simpleble_peripheral_mtu(handle);
}

BLEX_EXPORT BlexErrorCode blexPeripheralConnect(BlexPeripheral handle) {
  return simpleble_peripheral_connect(handle);
}

BLEX_EXPORT BlexErrorCode blexPeripheralDisconnect(BlexPeripheral handle) {
  return simpleble_peripheral_disconnect(handle);
}

BLEX_EXPORT BlexErrorCode blexPeripheralIsConnected(BlexPeripheral handle, bool* connected) {
  return simpleble_peripheral_is_connected(handle, connected);
}

BLEX_EXPORT BlexErrorCode blexPeripheralIsConnectable(BlexPeripheral handle, bool* connectable) {
  return simpleble_peripheral_is_connectable(handle, connectable);
}

BLEX_EXPORT BlexErrorCode blexPeripheralIsPaired(BlexPeripheral handle, bool* paired) {
  return simpleble_peripheral_is_paired(handle, paired);
}

BLEX_EXPORT BlexErrorCode blexPeripheralUnpair(BlexPeripheral handle) {
  return simpleble_peripheral_unpair(handle);
}

BLEX_EXPORT size_t     blexPeripheralGetServicesCount(BlexPeripheral handle) {
  return simpleble_peripheral_services_count(handle);
}

BLEX_EXPORT BlexErrorCode blexPeripheralGetServices(BlexPeripheral handle,
                                                size_t index,
                                          BlexService* services) {
  return simpleble_peripheral_services_get(handle, index, services);
}

BLEX_EXPORT size_t     blexPeripheralManufacturerDataCount(BlexPeripheral handle) {
  return simpleble_peripheral_manufacturer_data_count(handle);
}

BLEX_EXPORT BlexErrorCode blexPeripheralManufacturerDataGet(
    BlexPeripheral handle, size_t index, BlexManufacturerData* manufacturer_data
  ) {
  return simpleble_peripheral_manufacturer_data_get(handle, index, manufacturer_data);
}

BLEX_EXPORT BlexErrorCode blexPeripheralRead(BlexPeripheral handle,
                                       char* service,
                                       char* characteristic,
                                     size_t* data_length,
                                   uint8_t** data) {
  BlexUUID service_ = to_uuid(service), characteristic_ = to_uuid(characteristic);
  return simpleble_peripheral_read(handle, service_, characteristic_, data, data_length);
}

BLEX_EXPORT BlexErrorCode blexPeripheralWriteRequest(BlexPeripheral handle,
                                                char* service,
                                                char* characteristic,
                                                  size_t data_length,
                                                uint8_t* data) {
  BlexUUID service_ = to_uuid(service), characteristic_ = to_uuid(characteristic);
  return simpleble_peripheral_write_request(handle, service_, characteristic_, data, data_length);
}

BLEX_EXPORT BlexErrorCode blexPeripheralWriteCommand(
                                             BlexPeripheral handle,
                                              char* service,
                                              char* characteristic,
                                             size_t data_length,
                                              uint8_t* data) {
  BlexUUID service_ = to_uuid(service), characteristic_ = to_uuid(characteristic);
  return simpleble_peripheral_write_command(handle, service_, characteristic_, data, data_length);
}

BLEX_EXPORT BlexErrorCode blexPeripheralNotify(BlexPeripheral handle,
                                              char* service,
                                              char* characteristic,
                                              void (*callback)(const char* service, const char* characteristic, const uint8_t* data, size_t data_length)
                                              ) {
  BlexUUID service_ = to_uuid(service), characteristic_ = to_uuid(characteristic);
  return simpleble_peripheral_notify(handle, service_, characteristic_, callback);
}

BLEX_EXPORT BlexErrorCode blexPeripheralIndicate(BlexPeripheral handle,
                                              char* service,
                                              char* characteristic,
                                              void (*callback)(const char* service, const char* characteristic, const uint8_t* data, size_t data_length)
                                              ) {
  BlexUUID service_ = to_uuid(service), characteristic_ = to_uuid(characteristic);
  return simpleble_peripheral_indicate(handle, service_, characteristic_, callback);
}

BLEX_EXPORT BlexErrorCode blexPeripheralUnsubscribe(BlexPeripheral handle,
                                              char* service,
                                              char* characteristic) {
  BlexUUID service_ = to_uuid(service), characteristic_ = to_uuid(characteristic);
  return simpleble_peripheral_unsubscribe(handle, service_, characteristic_);
}

BLEX_EXPORT BlexErrorCode blexPeripheralReadDescriptor(BlexPeripheral handle,
                                                  char* service,
                                                  char* characteristic,
                                                  char* descriptor,
                                                  size_t* data_length,
                                                uint8_t** data) {
  BlexUUID service_ = to_uuid(service), characteristic_ = to_uuid(characteristic), descriptor_ = to_uuid(descriptor);
  return simpleble_peripheral_read_descriptor(handle, service_, characteristic_, descriptor_, data, data_length);
}

BLEX_EXPORT BlexErrorCode blexPeripheralWriteDescriptor(BlexPeripheral handle,
                                                  char*  service,
                                                  char*  characteristic,
                                                  char*  descriptor,
                                                  size_t data_length,
                                            const uint8_t* data) {
  BlexUUID service_ = to_uuid(service), characteristic_ = to_uuid(characteristic), descriptor_ = to_uuid(descriptor);
  return simpleble_peripheral_write_descriptor(handle, service_, characteristic_, descriptor_, data, data_length);
}

BLEX_EXPORT BlexErrorCode blexPeripheralSetCallbackOnConnected(BlexPeripheral handle,
                                                            void (*callback)(BlexPeripheral peripheral, void* userdata),
                                                            void* userdata) {
  return simpleble_peripheral_set_callback_on_connected(handle, callback, userdata);
}

BLEX_EXPORT BlexErrorCode blexPeripheralSetCallbackOnDisconnected(BlexPeripheral handle,
                                                               void (*callback)(BlexPeripheral peripheral, void* userdata),
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


BLEX_EXPORT int main() {
  printf("Test BLEX module :: ");
  bool is_enabled = blexAdapterIsBluetoothEnabled();
  if (is_enabled) {
    printf("BLEX is enabled\n");
  } else {
    printf("BLEX is not enabled\n");
  }
}

#ifdef __cplusplus
}
#endif
