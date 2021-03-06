import { connect } from 'react-redux'

import { ChangePassword  } from '../actions'
import GMSetting from './GMSetting'

const mapStateToProps = (state, ownProps) => {
  return {
  open: ownProps.open,
  onSettingClose: ownProps.onSettingClose,
  errorMessage: state.userData.auth.changepasswordError,
  accountname: state.userData.auth.changePasswordEmail
  }
}

const mapDispatchToProps = (dispatch) => {
  return{
    onClickChangePassword: (creds) => {
      dispatch(ChangePassword(creds))
    }
  }
}

const GMSettingContainer = connect(
  mapStateToProps,
  mapDispatchToProps
)(GMSetting)

export default GMSettingContainer
